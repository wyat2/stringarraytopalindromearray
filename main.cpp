#include <iostream>
#include <cstring>

using namespace std;

int size = 5;

bool palindrome(char* word);

char** get_palindromes(char** arrayX, int& count, int& i)
{
    if(i >= size)
        return new char*[count];

    //count palindromes from arrayX
    if(palindrome(arrayX[i])) 
        ++count;

    // recursive call
    char** arrayB = get_palindromes(arrayX, count, ++i);
    --i;
    // insert into new array
    if(palindrome(arrayX[i]))
    {
          arrayB[--count] = new char[strlen(arrayX[i])+1];
          strcpy(arrayB[count], arrayX[i]);
    }
    
    return arrayB;
}
    

// helper function
bool palindrome(char* word)
{
    int a = 0;
    int z = strlen(word) - 1;

    while(a < z)
        if(word[a++] != word[z--])
            return false;
    return true;
}

int main()
{
    int c = 0;
    int i = 0;
    
    char** arrayA = new char*[size];
    arrayA[0] = new char[5];
    strcpy(arrayA[0],"blue");
    arrayA[1] = new char[6];
    strcpy(arrayA[1],"madam");
    arrayA[2] = new char[7];
    strcpy(arrayA[2],"yellow");
    arrayA[3] = new char[7];
    strcpy(arrayA[3],"nurrun");
    arrayA[4] = new char[6];
    strcpy(arrayA[4],"black");

    char** arrayB = get_palindromes(arrayA, c, i); 
 
    cout << "Display Array B" << endl;
    cout << arrayB[0] << endl;
    cout << arrayB[1] << endl;
return 0;
}
