#include "header.h"
#include "unity.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

int test_grid_mode(int);
int test_islanded_mode(int );
int test_power_calculation(int );


int test_grid_mode(int){
    TEST_ASSERT_EQUAL(1200,1000,200);
    TEST_ASSERT_EQUAL(1000,1200,400);
}
int test_islanded_mode(int ){
    TEST_ASSERT_EQUAL(1200,1000,200);
    TEST_ASSERT_EQUAL(1400,1200,400);
}
int test_power_calculation(int ){
    TEST_ASSERT_EQUAL(1200,200);
    TEST_ASSERT_EQUAL(1400,200);
}

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
