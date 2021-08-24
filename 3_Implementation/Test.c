#include "header.h"
#include "unity.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

int test_grid_mode(int,int,int);
int test_islanded_mode(int,int,int);
int test_power_calculation(int,int);
int test_isFileExists(char);
void test_wait(int wait)


void test_grid_mode(void){
   TEST_ASSERT_EQUAL((500), test_grid_mode(2500,2000,200));
   TEST_ASSERT_EQUAL((600), test_grid_mode(2000,1500,300));
   TEST_ASSERT_EQUAL((700), test_grid_mode(3000,1000,150));
}
void test_islanded_mode(void ){
   TEST_ASSERT_EQUAL((600), test_islanded_mode(90,1600,1000));
   TEST_ASSERT_EQUAL((500), test_islanded_mode(100,1700,2000));
   TEST_ASSERT_EQUAL((400), test_islanded_mode(2000,1600,100));

}
void test_power_calculation(void ){
    TEST_ASSERT_EQUAL((500), test_power_calculation(1200,200));
    TEST_ASSERT_EQUAL((500), test_power_calculation(1300,300));
    TEST_ASSERT_EQUAL((500), test_power_calculation(1000,100));
}
void test_isFileExists(void){
  TEST_ASSERT_EQUAL((500), test_isFileExists(200));
}
void test_wait(void){
  TEST_ASSERT_EQUAL((1),test_wait(1));
}

int main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_grid_mode);
  RUN_TEST(test_islanded_mode);
  RUN_TEST(test_power_calculation);
  RUN_TEST(test_isFileExists);
  RUN_TEST(test_wait);

  /* Close the Unity Test Framework */
  return UNITY_END();
}
