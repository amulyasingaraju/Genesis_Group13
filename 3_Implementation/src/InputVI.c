
int AdminInput()
{
    int voltage;
    int current;
    printf(" Enter Voltage requirement:   "); 
    scanf(" %d", &voltage);
    printf(" Enter Current requirement:   "); 
    scanf(" %d", &current);
    printf(" The amount of voltage and current required by EV is: Voltage = %d V, Current = %d Amp", voltage ,current);
    return voltage,current;
}


