#include "company.hpp"


// Initializes the tracker with n students and their 1-person companies.
CompanyTracker::CompanyTracker(int n)
{
  std::cout << "ctor running for " << n << std::endl;

  numCompanies = n;
  if (numCompanies > 0) {

    companies = new Company* [numCompanies];
    
    for (int i = 0; i < numCompanies; ++i) {
        companies[i] = new Company ();
        bigComp.push_back(companies[i]);
    }
    
    realPrint();

    std::cout << "ctor ran for " << numCompanies << std::endl;
  }
}

// Deallocates all dynamically allocated memory.
CompanyTracker::~CompanyTracker()
{

  /*

  if (numCompanies > 0) {

    for (int i = 0; i < numCompanies; i++) {
      
      delete companies[i];  
      companies[i] = nullptr;                         // CHECK ME: Am i deallocating correctly
    }
    delete [] companies; 
    companies = nullptr;

  }
  */

  std::cout << "dtor running for " << numCompanies << std::endl;

 std::cout << "big comp size is " << bigComp.size() << std::endl;

  if (numCompanies > 0) {
    for(unsigned int i = 0; i < bigComp.size(); ++i){

      std::cout << i << std::endl;
      clearMem(bigComp[i]);

    }
    delete [] companies;
  }

  std::cout << "dtor ran for " << numCompanies << std::endl;

}

void CompanyTracker::merge(int i, int j)
{

  // Check if student value are both in range
  if (inRange(i) && inRange(j)) {

    // CHECK if i and j are in the same company
    if (!inSameCompany(i,j)) {

      // Check if inputted in wrong order, then swap if necessary
      if (i > j) {
        int temp = i;
        i = j;
        j = temp;
      }

      // Check which company has the smallest index
      int oneID = dfs(largestCompany(i));
      int twoID = dfs(largestCompany(j));

      // Swap if i and j oneID has a larger index than twoID
      // This ensures the smaller index goes first when creating
      // the new company object below for new Company(one, two)
      if (oneID > twoID) {
        int temp = i;
        i = j;
        j = temp;
      }

      // CHECK if i or j are subcompanies, find the largest
      Company* one = largestCompany(i);
      Company* two = largestCompany(j);  

      // Create a new company of those two companies      
      Company* comp = new Company( one, two );

      // Assign parents of subcomapnies to new comp
      one -> parent = comp;
      two -> parent = comp; 

      int oneIndex = -1;
      int twoIndex = -1;

      // Find indexes of the companies to see which is larger
      for (unsigned int i = 0; i < bigComp.size(); i++) {

        if (bigComp[i] == one) {
          oneIndex = i;
        }
        if (bigComp[i] == two) {
          twoIndex = i;
        }
      }

      // Erase the company at the larger index
      bigComp.erase(bigComp.begin() + twoIndex);

      // Place new company at the smaller index
      bigComp[oneIndex] = comp;

      realPrint();
    }
  }

  //printList(companies[0]);

  return; 
}


void CompanyTracker::split(int i)
{
  // your implementation goes here

  // Check if i is in range
  if (inRange(i)) {

    // Find the largest company i is apart of
    Company* large = largestCompany(i);   

    // Check if i is not a 1-person Company
    // Otherwise split will do nothing
    if (large -> merge1 != nullptr ) {
      
      // Find the two comapnies i is composed of
      // Set both subcompanies' parents to NULL
      large -> merge1 -> parent = nullptr;
      large -> merge2 -> parent = nullptr;

      int largeIndex = -1;
      //int twoIndex = -1; 

      // Find index of the company to be split
      for (unsigned int i = 0; i < bigComp.size(); i++) {
        if (large == bigComp[i]) {
          largeIndex = i;
        }
      }

      // Replace large company with merge 1
      // Since list is organzie small to large
      bigComp[largeIndex] = large -> merge1;

      Company* curr = large -> merge2;

      // Use DFS to find index of smallest company
      unsigned int ID = dfs(curr);

      // If ID exceeds size of bigComp
      if (ID > bigComp.size()) {
        bigComp.insert(bigComp.end(), curr);

      }
      else {
        for (unsigned int i = largeIndex; i < bigComp.size(); i++) {
          


          // Find where in the vector the company belongs to maintain order
          if (ID < dfs(bigComp[i])) {
            bigComp.insert(bigComp.begin() + i, curr);

            //std::cout << i << std::endl;
            break;
          }
        }
      }

    }

    realPrint();
  }

  return; 
}

bool CompanyTracker::inSameCompany(int i, int j)
{
  // your implementation goes here
  // Check if student value are both in range
  if (inRange(i) && inRange(j)) {

    // Use the largestCompany function to find the parents, if they exist
    // If parents are same, bool returns true, they are in same comp
    return ( largestCompany(i) == largestCompany(j) );
  }
  // Return false if student values are not in range
  else {
    return false;
  }
}


Company* CompanyTracker::largestCompany(int i) {

  // Keep on finding parents until parent is the nullptr
  // Then you will know that this is the Largest Company
  Company* curr = companies[i];
  while(curr->parent != nullptr){
    curr = curr->parent;
  }
  return curr;

}


bool CompanyTracker::inRange(int i) {

  // Cannot exceed number of companies that exist
  return ( (i >= 0) && (i < numCompanies) );
}


void CompanyTracker::printList(Company* comp) {

  // Base Case 1
  if (comp == nullptr) {
    return;
  }

  //Base Case 2: No more children companies
  if (comp -> merge1 == nullptr) {
    int ID = -1;

    // Search for Company ID
    for (int i = 0; i < numCompanies; i++) {
      if (comp == companies[i]) {
        ID = i;
        break;
      }
    }
    // Print Company ID
    std::cout << "{" << ID << "}";
    return;
  }

    std::cout << "{ ";
    printList(comp -> merge1);

    std::cout << ", ";
    printList(comp -> merge2);

    std::cout << " }";

  return; 
}


int CompanyTracker::dfs(Company* comp) {

  int ID = 1000000;

  // Base Case 1: This company node has no children
  if(comp == nullptr){
    return 100000000;
  }
  // Base Case 2
  if (comp -> merge1 == nullptr) {
    // Find compnay index
    for (int i = 0; i < numCompanies; i++) {

      // Find company index
      if (comp == companies[i]) {
        ID = i;

        // Check if minimum value
        break;
      }
    }
    return ID; 
  }
  // DFS both children of this company
  
  int one = dfs(comp -> merge1);
  int two = dfs(comp -> merge2);

  int min = ID;

  // Find min of one, two and ID
  if (two < one) {
    one = two;
  }

  if (one < ID) {
    min = one;
  }

  return(min);

}

void CompanyTracker::realPrint() {
  for (unsigned int i = 0; i < bigComp.size() - 1; i++) {
    printList(bigComp[i]);
    std::cout << ", ";
  }
  printList(bigComp[bigComp.size()-1]);
  std::cout << std::endl;
}

// Delete dynamically allcoated companies
void CompanyTracker::clearMem(Company* comp) {

  // Base Case: 
  if (comp == nullptr) {
    return;
  }

  clearMem(comp->merge1);
  clearMem(comp->merge2);
  delete comp;
  comp = nullptr;


}
