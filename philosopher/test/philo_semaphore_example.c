/*
    philo example

*/

philosopher_i

while (1)
{
    pickup();
    eat();
    putdown();
    sleep();
    think();
}

void    putdown(int i)
{
    P(mutex);
    state[i] = thinking;
    test((i+4) % 5);
    test((i+1) % 5);
    V(mutex);
}

void    pickup(int i)
{
    P(mutex);
    state[i] = HUNGRY;
    test(i);
    V(mutex);
    P(self[i]);
}

void    test(int i)
{
    if (state[(i+4)%5] != EATING && state[i] == HUNGRY 
        && state[(i + 1) % 5] != EATING)
    {
        state[i] = EATING;
        V(self[i]);
    }
}
