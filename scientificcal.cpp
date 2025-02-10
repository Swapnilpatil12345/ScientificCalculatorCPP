#include <iostream>
#include <cmath>
#include <iomanip>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

double general_calculation();
bool isOperator(char c);
int getPrecedence(char op);
double applyOperation(double a, double b, char op);
double evaluateExpression(string expression);
void Linear_equn_2();
void Linear_equn_3();
void quadratic();
void trigonometry();
void generateHarmonicProgression();
void generateGeometricProgression();
void generateArithmeticProgression();
void crossMultiplyMatrices(int **matrix1, int **matrix2);
void dotMultiplyMatrices(int **matrix1, int **matrix2, int order);
void subtractMatrices(int **matrix1, int **matrix2, int order);
void addMatrices(int **matrix1, int **matrix2, int order);
int main()
{
    cout << "\n \n \n " << endl;
    cout << "**************WELCOME TO OUR CALCULATOR************** " << endl;
    cout << "\t \t \t Press Following Keys To Perform Required Operation " << endl;
    cout << "\t \t \t \t 1 --> General Calculation" << endl;
    cout << "\t \t \t \t 2 --> linear Equation Solver" << endl;
    cout << "\t \t \t \t 3 --> Quadratic Equation Solver" << endl;
    cout << "\t \t \t \t 4 --> Trigonetric Calculation " << endl;
    cout << "\t \t \t \t 5 --> Sequence Solver " << endl;
    cout << "\t \t \t \t 6 --> Matrix operation " << endl;
    cout << "\t \t \t \t 7 --> Unit Conversion " << endl;

    int key;
    cin >> key;
    if (key == 1)
    {
        cout << "Processing towards general calculation ......." << endl;
        general_calculation();
    }
    else if (key == 2)
    {
        cout << "Processing towards linear Equation Solver ......." << endl;
        cout << "Enter no. of Variables 2 or 3 : ";
        int var;
        cin >> var;
        if (var == 2)
        {
            Linear_equn_2();
        }
        else if (var == 3)
        {
            Linear_equn_3();
        }
        else
        {
            cout << "The solver is not yet developed for enter no.of variables" << endl;
        }
    }
    else if (key == 3)
    {
        cout << "Processing towards Quadratic Equation Solver ......." << endl;
        quadratic();
    }
    else if (key == 4)
    {
        cout << "Processing towards Trigonetric Calculation ......." << endl;
        trigonometry();
    }
    else if (key == 5)
    {
        cout << "Processing towards Sequence Solver ......." << endl;
        cout << "Enter following key for operation you want to perform " << endl;
        cout << "\t 1 --> Arithematic progresion" << endl;
        cout << "\t 2 --> Geometric progression" << endl;
        cout << "\t 3 --> Harmonic progression " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            generateArithmeticProgression();
            break;
        case 2:
            generateGeometricProgression();
            break;
        case 3:
            generateHarmonicProgression();
            break;

        default:
            cout << "Invalid Choice !";
            break;
        }
    }
    else if (key == 6)
    {
        cout << "Processing towards Sequence Solver ......." << endl;
        int order1, order2;

        cout << "Enter the order of the first matrix (2 or 3): ";
        cin >> order1;

        cout << "Enter the order of the second matrix (2 or 3): ";
        cin >> order2;

        if (order1 != order2)
        {
            cout << "Matrix orders should be the same for addition, subtraction, and dot multiplication!" << endl;
            return 0;
        }

        int **matrix1 = new int *[order1];
        int **matrix2 = new int *[order2];

        cout << "Enter the elements of the first matrix:\n";
        for (int i = 0; i < order1; i++)
        {
            matrix1[i] = new int[order1];
            for (int j = 0; j < order1; j++)
            {
                cin >> matrix1[i][j];
            }
        }

        cout << "Enter the elements of the second matrix:\n";
        for (int i = 0; i < order2; i++)
        {
            matrix2[i] = new int[order2];
            for (int j = 0; j < order2; j++)
            {
                cin >> matrix2[i][j];
            }
        }
        int choice;
        cout << "Press following keys for performing the respective  Operation" << endl;
        cout << "\t 1 --> Addition of matrix" << endl;
        cout << "\t 2 --> Substraction of matrix" << endl;
        cout << "\t 3 --> Dot Multiplication of matrix" << endl;
        cout << "\t 4 --> Cross Multiplication of matrix" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            addMatrices(matrix1, matrix2, order1);
            break;
        case 2:
            subtractMatrices(matrix1, matrix2, order1);
            break;
        case 3:
            dotMultiplyMatrices(matrix1, matrix2, order1);
            break;
        case 4:
            if (order1 == 3 && order2 == 3)
            {
                crossMultiplyMatrices(matrix1, matrix2);
            }
            else
            {
                cout << "Not Developed yet !";
            }
            break;

        default:
            cout << "Invalid Choice !";
            break;
        }
        // Deallocate memory
        for (int i = 0; i < order1; i++)
        {
            delete[] matrix1[i];
            delete[] matrix2[i];
        }
        delete[] matrix1;
        delete[] matrix2;

        return 0;
    }
}

double general_calculation()
{
    string expression;

    cout << "Enter an arithmetic expression: " << endl;
    cin >> expression;

    double result = evaluateExpression(expression);

    cout << "Result: " << result << endl;

    return 0;
}
// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get the precedence of an operator
int getPrecedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

// Function to perform arithmetic operations
double applyOperation(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow(a, b);
    default:
        cout << "invalid Operation";
        return 0;
    }
}

// Function to evaluate the expression using BODMAS rule

double evaluateExpression(string expression)
{
    stack<double> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); i++)
    {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i]))
        {
            // Read the number and push it to the values stack
            string numStr;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.'))
            {
                numStr += expression[i];
                i++;
            }
            i--;

            double num = stod(numStr);
            values.push(num);
        }
        else if (expression[i] == '(')
        {
            // Push opening parenthesis to the operators stack
            operators.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            // Evaluate the expression within parentheses
            while (!operators.empty() && operators.top() != '(')
            {
                double b = values.top();
                values.pop();

                double a = values.top();
                values.pop();

                char op = operators.top();
                operators.pop();

                double result = applyOperation(a, b, op);
                values.push(result);
            }

            if (!operators.empty())
                operators.pop(); // Pop the opening parenthesis
        }
        else if (isOperator(expression[i]))
        {
            // Evaluate higher precedence operators before the current operator
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(expression[i]))
            {
                double b = values.top();
                values.pop();

                double a = values.top();
                values.pop();

                char op = operators.top();
                operators.pop();

                double result = applyOperation(a, b, op);
                values.push(result);
            }

            // Push the current operator to the operators stack
            operators.push(expression[i]);
        }
    }

    // Evaluate the remaining operators in the stack
    while (!operators.empty())
    {
        double b = values.top();
        values.pop();

        double a = values.top();
        values.pop();

        char op = operators.top();
        operators.pop();

        double result = applyOperation(a, b, op);
        values.push(result);
    }

    // The final result will be at the top of the values stack
    return values.top();
}

void quadratic()
{
    float a, b, c, x1, x2, discriminant, real, imaginary;
    // General form ax^2+bx+c=0
    cout << "Enter coefficients x^2, x and constant: ";
    cin >> a >> b >> c;
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and different." << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }

    else if (discriminant == 0)
    {
        cout << "Roots are real and Equal." << endl;
        x1 = -b / (2 * a);
        cout << "x1 = x2 =" << x1 << endl;
    }

    else
    {
        real = -b / (2 * a);
        imaginary = sqrt(-discriminant) / (2 * a);
        cout << "Roots are complex and different." << endl;
        cout << "x1 = " << real << "+" << imaginary << "i" << endl;
        cout << "x2 = " << real << "-" << imaginary << "i" << endl;
    }
}
void Linear_equn_3()
{
    float a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, D, D1, D2, D3, x, y, z;
    cout << "General form of equation: a1x+b1y+c1=d1 , a2x+b2y+c2=d2 and a2x+b3y+c3=d3 \n";
    cout << "Enter the values of a1,b1,c1,d1 and a2,b2,c2,d2  and a3,b3,c3,d3 respectively\n";
    cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2 >> a3 >> b3 >> c3 >> d3;
    D = a1 * (b2 * c3 - c2 * b3) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
    D1 = d1 * (b2 * c3 - c2 * b3) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2);
    D2 = a1 * (d2 * c3 - c2 * d3) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2);
    D3 = a1 * (b2 * d3 - d2 * b3) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2);
    cout << "D = " << D << endl;

    if (D == 0)
    {
        if (D1 == 0 && D2 == 0 && D3 == 0)
        {
            cout << "The  system of equations is consistent and it has infinitely many solutions.";
        }
        else
        {
            cout << "The system of equations is inconsistent and it has no solution.";
        }
    }
    else
    {
        cout << "D1= " << D1 << endl;
        cout << "D2= " << D2 << endl;
        cout << "D3= " << D3 << endl;
        x = D1 / D;
        y = D2 / D;
        z = D3 / D;
        cout << "Solution: " << endl
             << setprecision(3) << "x= " << x << endl
             << setprecision(3) << "y= " << y << endl
             << setprecision(3) << "z= " << z;
    }
}

void Linear_equn_2()
{
    float a1, a2, b1, b2, c1, c2, D, D1, D2, x, y;
    cout << "General form of equation: a1x+b1y=c1 and a2x+b2y=c2\n";
    cout << "Enter the values of a1,b1,c1 and a2,b2,c2 respectively\n";
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    D = (a1 * b2) - (a2 * b1);
    D1 = (c1 * b2) - (b1 * c2);
    D2 = (a1 * c2) - (c1 * a2);
    cout << "D= " << D << endl;

    if (D == 0)
    {
        if (D1 == 0 && D2 == 0)
        {
            cout << "The  system of equations is consistent and it has infinitely many solutions." << endl;
        }
        else
        {
            cout << "The system of equations is inconsistent and it has no solution.";
        }
    }
    else
    {
        cout << "D1= " << D1 << endl;
        cout << "D2= " << D2 << endl;
        x = D1 / D;
        y = D2 / D;
        cout << "Solution: " << endl
             << setprecision(3) << "x= " << x << endl
             << setprecision(3) << "y= " << y;
    }
}
void trigonometry()
{
    int choice;
    double angle, result;

    cout << "Enter your choice (1-6): ";
    cout << "Trigonometric Calculator" << endl;
    cout << "1. Sine" << endl;
    cout << "2. Cosine" << endl;
    cout << "3. Tangent" << endl;
    cout << "4. Inverse Sine" << endl;
    cout << "5. Inverse Cosine" << endl;
    cout << "6. Inverse Tangent" << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter the angle in degrees: ";
        cin >> angle;
        result = sin(angle * M_PI / 180.0);
        cout << "Sine of " << angle << " degrees: " << result << endl;
        break;
    case 2:
        cout << "Enter the angle in degrees: ";
        cin >> angle;
        result = cos(angle * M_PI / 180.0);
        cout << "Cosine of " << angle << " degrees: " << result << endl;
        break;
    case 3:
        cout << "Enter the angle in degrees: ";
        cin >> angle;
        result = tan(angle * M_PI / 180.0);
        cout << "Tangent of " << angle << " degrees: " << result << endl;
        break;
    case 4:
        cout << "Enter the value: ";
        cin >> angle;
        result = asin(angle) * 180.0 / M_PI;
        cout << "Inverse Sine of " << angle << ": " << result << " degrees" << endl;

    case 5:
        cout << "Enter the value: ";
        cin >> angle;
        result = acos(angle) * 180.0 / M_PI;
        cout << "Inverse Cosine of " << angle << ": " << result << " degrees" << endl;
        break;
    case 6:
        cout << "Enter the value: ";
        cin >> angle;
        result = atan(angle) * 180.0 / M_PI;
        cout << "Inverse Tangent of " << angle << ": " << result << " degrees" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;                               
    }
}
void generateGeometricProgression()
{
    int firstTerm, commonRatio, numTerms;
    cout << "Enter the first term: ";
    cin >> firstTerm;

    cout << "Enter the common difference: ";
    cin >> commonRatio;

    cout << "Enter the number of terms: ";
    cin >> numTerms;
    cout << "Geometric Progression: ";
    int term = firstTerm;
    for (int i = 0; i < numTerms; i++)
    {
        cout << term << " ";
        term *= commonRatio;
    }
    cout << endl;
}
void generateHarmonicProgression()
{
    int firstTerm, commonDifference, numTerms;
    cout << "Enter the first term: ";
    cin >> firstTerm;

    cout << "Enter the common difference: ";
    cin >> commonDifference;

    cout << "Enter the number of terms: ";
    cin >> numTerms;
    cout << "Harmonic Progression: ";
    double term = 1.0 / firstTerm;
    for (int i = 0; i < numTerms; i++)
    {
        cout << 1.0 / term << " ";
        term += commonDifference;
    }
    cout << endl;
}
void generateArithmeticProgression()
{
    int firstTerm, commonDifference, numTerms;
    cout << "Enter the first term: ";
    cin >> firstTerm;

    cout << "Enter the common difference: ";
    cin >> commonDifference;

    cout << "Enter the number of terms: ";
    cin >> numTerms;
    cout << "Arithmetic Progression: ";
    for (int i = 0; i < numTerms; i++)
    {
        int term = firstTerm + i * commonDifference;
        cout << term << " ";
    }
    cout << endl;
}
void addMatrices(int **matrix1, int **matrix2, int order)
{
    int **result = new int *[order];
    for (int i = 0; i < order; i++)
    {
        result[i] = new int[order];
        for (int j = 0; j < order; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    std::cout << "Addition Result:\n";
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// Function to subtract two matrices
void subtractMatrices(int **matrix1, int **matrix2, int order)
{
    int **result = new int *[order];
    for (int i = 0; i < order; i++)
    {
        result[i] = new int[order];
        for (int j = 0; j < order; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    std::cout << "Subtraction Result:\n";
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void dotMultiplyMatrices(int **matrix1, int **matrix2, int order)
{
    int **result = new int *[order];
    for (int i = 0; i < order; i++)
    {
        result[i] = new int[order];
        for (int j = 0; j < order; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < order; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    std::cout << "Dot Multiplication Result:\n";
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void crossMultiplyMatrices(int **matrix1, int **matrix2)
{
    int **result = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        result[i] = new int[3];
    }

    result[0][0] = matrix1[1][1] * matrix2[2][2] - matrix1[1][2] * matrix2[2][1];
    result[0][1] = -(matrix1[1][0] * matrix2[2][2] - matrix1[1][2] * matrix2[2][0]);
    result[0][2] = matrix1[1][0] * matrix2[2][1] - matrix1[1][1] * matrix2[2][0];
    result[1][0] = -(matrix1[0][1] * matrix2[2][2] - matrix1[0][2] * matrix2[2][1]);
    result[1][1] = matrix1[0][0] * matrix2[2][2] - matrix1[0][2] * matrix2[2][0];
    result[1][2] = -(matrix1[0][0] * matrix2[2][1] - matrix1[0][1] * matrix2[2][0]);
    result[2][0] = matrix1[0][1] * matrix2[1][2] - matrix1[0][2] * matrix2[1][1];
    result[2][1] = -(matrix1[0][0] * matrix2[1][2] - matrix1[0][2] * matrix2[1][0]);
    result[2][2] = matrix1[0][0] * matrix2[1][1] - matrix1[0][1] * matrix2[1][0];

    std::cout << "Cross Multiplication Result:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}