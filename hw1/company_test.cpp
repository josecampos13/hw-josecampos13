#include "company.hpp"
using namespace std;

int main() {

    CompanyTracker tester(5);
    
    tester.merge(0,1);
    tester.merge(0,4);           // 4 should move before 2 and 3
    tester.split(0);             // 4 should move back to end
    tester.merge(2,3);
    tester.inSameCompany(2,3);   // Should return true
    tester.merge(0,3);         
    tester.merge(0,1);           // Merging same company: Should NOT run

    tester.merge(-1,4);          // Merges Out of Range: These Should NOT run
    tester.merge(1,10);

    tester.split(-2);            // Splits Out of Range: These Should NOT run
    tester.split(10);

    tester.split(4);             // 4 is independent: Should NOT run

    tester.split(2);

    tester.merge(1,4);           // Should move 4 inward
    tester.split(0);             // Should move 4 back out

    tester.split(1);             // Should make 1 and 0 independent
    tester.split(1);             // Already 1-person company: Should NOT change anything
    tester.split(2);


    // Testing out of order merge inputs

    tester.merge(3,0);          // Should move company 3 to front with 0
    tester.merge(4,1);         
    tester.merge(2,0);         


    // Below are Company Tracker tests for Edge/Special Cases

    CompanyTracker testerNegative(-1);  

    CompanyTracker tester0(0);

    CompanyTracker tester1(1);

    CompanyTracker testerLarge(20);

    // TEST CASES NEGATIVE: for Negative numCompanies
    // None should run since no or "negative" companies exist

    // Merge function Tests
    testerNegative.merge(0,1);
    testerNegative.merge(-1, 5);

    // Split function Tests
    testerNegative.split(0);
    testerNegative.split(-1);
    testerNegative.split(10);

    //inSameCompany function Tests
    testerNegative.inSameCompany(-1, 5);
    testerNegative.inSameCompany(0, 1);
    testerNegative.inSameCompany(-1,-1);


    // TEST CASES ZERO: for 0 Companies
    // None should run since there are no comapnies

    // Merge function Tests
    tester0.merge(0,1);
    tester0.merge(-1, 5);

    // Split function Tests
    tester0.split(0);
    tester0.split(-1);
    tester0.split(10);

    //inSameCompany function Tests
    tester0.inSameCompany(-1, 5);
    tester0.inSameCompany(0, 1);
    tester0.inSameCompany(-1,-1);


    //TEST CASES SINGLE: for 1 Company

    // Merge function Tests
    tester1.merge(0,1);
    tester1.merge(-1, 5);

    // Split function Tests
    tester1.split(0);
    tester1.split(-1);
    tester1.split(10);

    //inSameCompany function Tests
    tester1.inSameCompany(1, 1);               // This should produce true or 1 ***CHECK***
    tester1.inSameCompany(0, 1);
    tester1.inSameCompany(-1,-1);


    //Test Cases 5: for many companies

    // Merge Function Tests
    testerLarge.merge(0,19);
    testerLarge.merge(5,13);
    testerLarge.merge(5,6);
    testerLarge.merge(17,19);
    testerLarge.merge(18,19);
    testerLarge.merge(10,17);
    testerLarge.merge(19,20);
    testerLarge.merge(5,16);
    testerLarge.merge(7,9);
    
    // Split Function Testers
    testerLarge.split(17);
    testerLarge.split(10);
    testerLarge.split(18);
    testerLarge.split(0);

    // inSameCompany Tests
    testerLarge.inSameCompany(7,9);            
    testerLarge.inSameCompany(0,19);
    testerLarge.inSameCompany(5,13);

    return 0;

}