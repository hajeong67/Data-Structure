/*
���� ���� �ùķ��̼� ���α׷��� �����Ͽ� �ڵ����� �ùķ��̼� �� �� �ִ� ���α׷��� �����ϰ� �����϶�
*/

#include "CircularSimulator.h"

int main(void)
{
    srand((unsigned)time(NULL));
    CircularSimulator sim;

    sim.readSimulationParameters();
    sim.run();
    sim.printStat();

    return 0;
}