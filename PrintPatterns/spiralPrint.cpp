#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

/***** Complete this program. *****/

/*The Function do_spiral: It does the initial checks required for the program to
 * proceed further. It determines whether the data provided is valid or not.
 * Apart from them the function calls make_spiral which holds the logic for 
 * spiral form.
 * @param: Constant n- the size of the matrix.
 * @param: Constant start - The initial start of the number.
 */
void do_spiral(const int n, const int start);

/*The Function make_spiral: It holds the logic of making the spiral form matrix.
 * The function is largely dependent on the positions of the radix's. The radix
 * are found out using the function measure_position.
 * @param: Constant n - The size if the matrix.
 * @param: Constant start - The initial start of the number.
 * @param: Matrix - The 2 Dimensional array which holds the data of all numbers.
 */
void make_spiral(const int n, const int start, int matrix[][MAX_SIZE]);

/*The Function measure_position: It holds the key to the output of the program.
 *The function is used to monitor the positions of the next Mode.
 *@param - temp_counter - This is the number of leads taken to reach the next 
 * spot.
 *@param - select mode - This is a string that helps us in selecting the next 
 * possible mode.
 *@param - row position - This provides us the next row position.
 *@param - coloumn position - This provides is the next coloumn positon
 *@param - position - This 2 Dimensional array holds up all the next move 
 * information, depending on the spiral movement. 
 */
void measure_position(int& temp_counter, string& select_mode, int& row_position, int& coloumn_posiition, int position[4][2]);

/*The Function number_of_zeros: It is used to calclulate the number of zeros 
 * in the Main 2 D array
 * this is used to come out of the loop in the make_spiral function.
 * @param - Constant n - The size of the matrix.
 * @param - matrix - The 2 Dimensional array. 
 */
int number_of_zeros(const int n, int matrix[][MAX_SIZE]);

/*The Function initialize_array: It is used to Initialize all the elements 
 * in the 2 Dimensional array as 0.
 *@param - Constant n - The size of the matrix.
 *@param - matix - The 2 Dimensional array to initialize.
 */
void initialize_array(const int n, int matrix [][MAX_SIZE]);

/*The Function print_spiral: Its used to print the final format of the 2 D Array.
 * @param - Constant n - Size of the matrix.
 * @param - start - Initial value of the number.
 * @param - Matrix - The 2D array supposed to be printed.
 */
void print_spiral(const int n, const int start, int matrix[][MAX_SIZE]);

/*The Function print_spiral: Its an overloaded Function to print the 
 * Erroneous inputs.
 * @param - constant n - THe size of the matrix;
 * @param - start - Initial value of the number to print.
 */
void print_spiral(const int n, const int start);

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);
    return 0;
}

void do_spiral(const int n, const int start)
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int middle = floor(n/2);
    
    initialize_array(n, matrix);                                                // Initializing the array to zeros.
    
    if( n % 2 == 0 )
    {
        print_spiral(n, start);
        return;
    }
    
    else if(n == 1)
    {
        matrix[middle][middle] = start;
        print_spiral(n, start, matrix);
        return;
    }
    
    else
    {
        make_spiral(n, start, matrix);
        print_spiral(n, start, matrix);
        return;
    }
}

void make_spiral(const int n, const int start, int matrix[][MAX_SIZE])
{
    int row = (floor (n/2));                                                    // To get the middle value or the first element to
    int coloumn = (floor (n/2));                                                // Update
    int multiple = n * n;
    int counter = start;
    int temp_counter = 1;
    int i = 0;
    int temp = 0;
    int position[4][2]={{0, 1}, {-1, 0}, {0, -1},{1, 0}};                       // Movement Array.
    int row_position = position[0][0];                                          // Initialized for the next position 
    int coloumn_position = position[0][1];                                      // according to clock wise direction.
    
    string mode[4] = {"MODE_RIGHT", "MODE_TOP",  "MODE_LEFT", "MODE_BOTTOM"};   // Following the clockwise notation.
    string initial = mode[0];                                                   // The first movement is right of the array.
    
    do 
    {
        temp = number_of_zeros(n, matrix);                                      // Function Call to calculate the number of zeros in the Matrix.
        
        i = temp_counter;
        while(i > 0)
        {
            matrix[row][coloumn] = counter++;
            row += row_position;
            coloumn += coloumn_position;
            i--;
        }
            
        measure_position(temp_counter, initial, row_position, coloumn_position, position);
    }
    while (multiple != temp);
    
    return;
}

void initialize_array(const int n, int matrix [][MAX_SIZE])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            matrix[i][j] = 0;
    }
    return;
}


void measure_position(int& temp_counter, string& initial, int& row_position, int& coloumn_position, int position[4][2])
{
    if( initial == "MODE_RIGHT")
    {
        initial = "MODE_TOP";
        row_position = position[1][0];
        coloumn_position = position[1][1];
    }
    
    else if(initial == "MODE_TOP")
    {
        initial = "MODE_LEFT";                                                  // When Moving left we have to cover an extra box,
        row_position = position[2][0];                                          // Since the below number would alredy be present.
        coloumn_position = position[2][1];
        temp_counter++;
    }
    
    else if(initial == "MODE_LEFT" )
    {
        initial = "MODE_BOTTOM";
        row_position = position[3][0];
        coloumn_position = position[3][1];
    }
     
    else
    {
        initial = "MODE_RIGHT";                                                 
        row_position = position[0][0];
        coloumn_position = position[0][1];
        temp_counter++;
    }
}

int number_of_zeros(int const n, int matrix[][MAX_SIZE])
{
    int value = 0;
    
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(matrix[i][j] != 0)
                value++;
        }
    }
    return value;
}

void print_spiral(const int n, const int start)
{
    cout << "Spiral of size " << n << " starting at " << start << endl;
    cout << "***** Error: Size " << n << " must be odd." << endl;
    cout << endl;
    return; 
}

void print_spiral(const int n, const int start, int matrix[][MAX_SIZE])
{
    cout << "Spiral of size " << n << " starting at " << start << endl;
    cout << endl;
    
    for ( int k = 0; k < n; k++)
    {
        for ( int l = 0; l < n; l++)
        {
            cout << right << setw(4) << matrix[k][l];
        }
        cout << endl;
    }       
    cout << endl;
    return;
}
