#include <iostream>
using namespace std;
void move(int n, char src, char dest, char aux)
{
    if (n == 1)
    {
        cout << "move from" << src << "to" << dest << endl;
    }
    else
    {
        move(n - 1, src, aux, dest);
        move(1, src, dest, aux);
        move(n - 1, aux, dest, src);
    }
}
int main()
{
    int n;
    cout << "enter the number of rings \n";
    cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}