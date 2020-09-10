#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <float.h>


//-----------------------------------------------------------------------------

int iszero (double value);
int lin_eq_sol (double a, double b, double *x1, double *x2);
int square_eq_sol (double a, double b, double c, double *x1, double *x2);
int solve_square(double *x1, double *x2);
void res_sq_sol(int roots, double *x1, double *x2);

int main()
{
    setlocale(LC_ALL, "Russian");

    double x1 = 0, x2 = 0;

    int roots = solve_square(&x1, &x2);

    res_sq_sol(roots, &x1, &x2);

    return 0;
}

int solve_square(double *x1, double *x2)
    {

    printf("����� ����� ���������� ��������� ���� ax^2+bx+c=0\n");
    printf("��� ������ ������� ��� ������������ ����������� ��������� a, b � c:\n");

    double a = 0, b = 0, c = 0;

    while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
        {
        printf("����������, ������� ������ �����, � ������ ��� :\n");
        fflush (stdin);
        }

    int roots = square_eq_sol(a, b, c, x1, x2);

    return roots;
    }

int square_eq_sol (double a, double b, double c, double *x1, double *x2)
    {

    if (iszero(a))
        return lin_eq_sol(b, c, x1, x2);
    else
        {
        int d = b*b - 4*a*c;

        if ((iszero(d) == 0) && (d < 0))
           {
            *x1 = *x2 = 0;
            return 0;
           }
        else if (iszero(d))
            {
            if (iszero(-b/2/a))
                 *x1 = *x2 = fabs(-b/2/a);
            else *x1 = *x2 = -b/2/a;
            return 1;
            }
        else if ((iszero(d) == 0) && (d > 0))
            {
            *x1 = (-b - sqrt(d))/2/a;
            *x2 = (-b + sqrt(d))/2/a;
            return 2;
            }
        }

    }

int lin_eq_sol (double a, double b, double *x1, double *x2)
    {

    if (iszero(a))
            {
            if (iszero(b))
                {
                *x1 = *x2 = 0;
                return -1;
                }
            else
                {
                *x1 = *x2 = 0;
                return 0;
                }
            }
    else
        {

        if (iszero(-b/a))
            *x1 = *x2 = fabs(-b/a); // ���� b = 0 ,�� ������� �� ����� 0,� �� -0
        else *x1 = *x2 = -b/a;

        return 1;
        }
    }

void res_sq_sol(int roots, double *x1, double *x2)
    {

    if (roots == 0)
        printf("� ���������, ������ ���\n");
    else if (roots == 1)
        printf("������ ��������� ���� � �����  %.8lf\n", *x1);
    else if (roots == 2)
        printf("����� ��������� ����� %.8lf � %.8lf\n", *x1, *x2);
    else if (roots == -1)
        printf("��������� ������ ��������� ����������\n");
    }

int iszero (double value)
    {

    if (fabs (value) < 1e-6)
        return 1;
    else
        return 0;
    }
