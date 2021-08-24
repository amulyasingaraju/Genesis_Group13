# TEST PLAN:

## Table no: High level test plan

| **Test ID** | **Description**                                              | **Exp I/P** | **Exp O/P** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  H_01       | Grid Mode(PV_Power, Load_Demand,ProfitGrid)  | (15000,10000,100) | 45 | 45 | Scenario Based |
|  H_02       | Islanded Mode(PV_Power, Load_Demand,ProfitGrid)  | (18000,12000,100) | 18|18 | Scenario Based |
|  H_03       | ADD PORT AVAILABILITY | 0/1 | PASS | PASS | |

## Table no: Low level test plan

| **Test ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**Type Of Test**  |    
|-------------|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  L_01       | Power Calculation (V,I) | (1200,100) | 120000|12000| Scenario Based |
|  L_02       | OWNER LogIn | ID, Password | PASS | PASS | |
|  L_03       | CONSUMER INTERFACE | Add amount | PASS | PASS | |

