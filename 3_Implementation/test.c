#include "header.h"
#include "unity.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Prototypes for all the test functions */
int grid_mode(int,int,int);
int islanded_mode(int,int,int);
int power_calculation(int,int);


/* Write all the test functions */ 
/**
 * @brief To check for system parameter, please use exit command after the system checks run once to head towards the test case evaluation
 * 
 */

void test_grid_mode(void){
   TEST_ASSERT_EQUAL((45), grid_mode(15000,10000,100));
   TEST_ASSERT_EQUAL((60), grid_mode(20000,12000,120));
   TEST_ASSERT_EQUAL((300), grid_mode(100000,56000,230));
}

void test_islanded_mode(void ){
   TEST_ASSERT_EQUAL((18), islanded_mode(18000,12000,100));
   TEST_ASSERT_EQUAL((63), islanded_mode(81000,60000,150));
   TEST_ASSERT_EQUAL((63), islanded_mode(110000,90000,200));

}
void test_power_calculation(void){
    TEST_ASSERT_EQUAL((120000), power_calculation(1200,100));
    TEST_ASSERT_EQUAL((81000), power_calculation(900,90));
    TEST_ASSERT_EQUAL((25000), power_calculation(500,50));
}

/* Start of the application test */

int main(void)
{
 /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

 /* Run Test functions */
  RUN_TEST(test_grid_mode);
  RUN_TEST(test_islanded_mode);
  RUN_TEST(test_power_calculation);
  

  /* Close the Unity Test Framework */
  return UNITY_END();
}
