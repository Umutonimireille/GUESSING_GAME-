#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
using namespace std;
int main(){
	start:
	int categoryIndex,trials;
	string word = "";
	string randomWord="";
	string letter;
	char decision;
	string names[] = {"alice","eden","lois","oxane","prince"};
	string countries[] = {"rwanda","kenya","uganda","burundi","tanzania"};
	string colors[] = {"red","white","green","blue","orange"};
	string animals[] = {"pig", "cow", "cat", "sheep", "goat", "rat"};
	string categories[] = {"names", "countries", "colors", "animals"};
	
	
	cout << "--------------WELCOME TO THE GUESSING GAME------------- \n \n \n";
	
	
	//display and choose category
	for(int i = 0; i <(sizeof(categories) / sizeof(*categories)); i++){
		cout << "\t"<< i + 1 << "." << categories[i] << endl;
	}
	cout << "Please select the category:  ";
	cin >> categoryIndex;
	
	// choose a random word;
	srand(time(0));
	int random = rand() % 5;
	switch(categoryIndex){
	
    	case 1:
			word = names[random];
			break;
		case 2:
			word = countries[random];
			break;
		case 3:
			word = colors[random];	
			break;
		case 4:
			word = animals[random];		
	}
	trials = word.length() - 1;
	
	for(int i = 0; i<word.length(); i++){
		randomWord.replace(i,1, "-");
	}
	//choose a letter of the alphabet
	int j = 5;
	
	while(j > 0){
		if(randomWord.compare(word) == 0){
			break;
		}
		cout << "\n \n -Choose any alphabet: " <<  endl;
		cin >> letter;
		if(letter.compare("exit") == 0){
			exit(0);
		}
		for(int i = 0; i < word.length(); i++) {
			if(tolower(word[i])== letter[0]){
	    		randomWord[i] = letter[0];
	    	}
		}
		for(int i = 0; i < randomWord.length(); i++){
			if(randomWord[i]){
				cout << randomWord[i];
			}else{
				cout << "-";
			}
		}
		cout << endl << "===" << j << " trials"<<"===";
		j--;
	}
	
	for(int i=0; i < randomWord.length() ;i++){
		if(randomWord[i] == '-'){
			cout << "\n ====YOU LOSE===";
			goto decision;
		}
	}
	cout << "\n \n------YOU WIN----";	
	decision:
	cout << "\n Do you want to restart? (y/n): ";
	cin >> decision;
    if(decision == 'y'){
   		goto start;
    }else{
    	exit(0);
	}
	return 0;
}
