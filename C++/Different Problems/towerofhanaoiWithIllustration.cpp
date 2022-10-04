//Tower Of Hanoi
#include <iostream>
#include<iomanip>
using namespace std;

void towerOfHanoi(int n, char src_rod,
                    char destination_rod, char aux_rod)
{
    if (n == 1)//test for base case or stop case
    {
        cout << "Disk 5 moved from rod " << src_rod <<
                                       " to rod " << destination_rod<<endl;
        return;//base cases
    }

    towerOfHanoi(n - 1, src_rod, aux_rod, destination_rod);//recursive call
    cout << "Disk " << n << " moved from rod " << src_rod <<
                                       " to rod " << destination_rod << endl;//print statement

    towerOfHanoi(n - 1, aux_rod, destination_rod, src_rod);// again recursive call
}
int main()
{

    system("color 70");//Changing font color of the system
    int n=3; // Number of disks
    char destination_rod,aux_rod,ch;
    do{ //start of do-while loop to repeat the program
    // We can also take number of disks by user but here i have chosen 3 to display the disks in output stream
    cout<<endl<<endl;
    cout<<setw(80)<<"*****************************************************" <<endl;
    cout<<setw(80)<<"               WELCOME TO TOWER OF HANOI                "<<endl;
    cout<<setw(80)<<"*****************************************************" <<endl;
    cout<<endl<<endl;
    cout<<"Let Us Start with 3 Disks which are Intially at Tower A\n";
        cout<<"    Tower A          Tower B      Tower C\n";
        cout<<"        ||              ||           ||  \n";
        cout<<"        ||              ||           ||  \n";
        cout<<"        ||              ||           ||  \n";
        cout<<"      ******            ||           ||  \n";
        cout<<"   **************       ||           ||  \n";
        cout<<"********************    ||           || \n";
        cout<<"________________________________________\n";
        cout<<endl;
    cout<<"So at Which tower Do You want to move Disks? B OR C";
    cin>>destination_rod;// getting destination rod from user
   aux_rod=(destination_rod=='B' || destination_rod=='b')?'C':'B';// ternary operator to determine the value of auxilory rod
   cout<<endl;
   // setting source rod A bcz disks are initially at Rod A
    towerOfHanoi(n,'A',destination_rod,aux_rod); // A, B and C are names of rods
     if(destination_rod=='B'||destination_rod=='b'){//if condition to display the disks after they are moved
        cout<<"Tower A       Tower B       Tower C\n";
        cout<<" ||             ||             ||\n";
        cout<<" ||             ||             ||\n";
        cout<<" ||             ||             ||\n";
        cout<<" ||           ******           ||\n";
        cout<<" ||       **************       ||\n";
        cout<<" ||    ********************    ||\n";
        cout<<"____________________________________\n";

    }if(destination_rod=='C'||destination_rod=='c')
    {
      cout<<"Tower A  Tower B         Tower C           \n";
        cout<<" ||      ||              ||              \n";
        cout<<" ||      ||              ||              \n";
        cout<<" ||      ||              ||              \n";
        cout<<" ||      ||            ******            \n";
        cout<<" ||      ||        **************        \n";
        cout<<" ||      ||     ********************     \n";
        cout<<"_________________________________________\n";

    }

     cout<<"Do You want To Repeat? Press Y(Yes) OR N(No)";
     cin >>ch;
     }while(ch=='Y'||ch=='y');// end of while loop
        cout<<endl<<endl;
        cout<<setw(80)<<"Presented By SHAHAB MALIK \n";
    return 0;
}
