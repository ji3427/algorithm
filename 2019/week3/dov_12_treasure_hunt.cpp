#include <iostream>

using namespace std;

int main(void)
{
	int goal_row,goal_col;
	cin>>goal_col>>goal_row;
	int size,num;
	int row = 0;
	int col = 0;
	cin>>size;
	char direction;
	for(int i = 0 ; i < size ; i++){
		cin>>num;
		cin>>direction;
		if(direction == 'E') col += num;
		else if(direction == 'W') col -= num;
		else if(direction == 'N') row += num;
		else if(direction == 'S') row -= num;
	//	cout<<row<<" "<<col<<endl;
	}
	if(goal_col == col && goal_row == row) cout<<"Treasure Found"<<endl;
	else cout<<"Bad Map"<<endl;
}
