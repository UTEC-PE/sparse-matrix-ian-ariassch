#ifndef MATRIX_H
#define MATRIX_H

#include "node.h"

using namespace std;

template <typename T>
class Matrix {
    private:
        Node<T>* hRows;
        Node<T>* hColumns;
        int columns;
        int rows;

    public:
        Matrix(){};
        Matrix(int sizeX, int sizeY)
        {

            hRows = new Node<T>;
            hColumns = new Node<T>;
            columns=sizeX;
            rows=sizeY;
            hRows->data=0;
            hRows->x=0;
            hRows->y=1;
            hColumns->data=0;
            hColumns->x=1;
            hColumns->y=0;
            auto *tempn = hColumns;
            auto *tempd = hRows;
            for(int x=1; x<=sizeX; x++)
            {
                auto *temp = new Node<T>;
                tempn->next=temp;
                temp->x=x;
                temp->y=0;
                temp->data=x;
                tempn = temp;
            }
            for(int y=1; y<=sizeY; y++)
            {
                auto *temp = new Node<T>;
                tempd->down=temp;
                temp->x=0;
                temp->y=y;
                temp->data=y;
                tempd = temp;
            }

        }

        void set(int x, int y, T data)
        {
            if(get(x,y) != NULL)
            {
                auto *temp = hColumns;

                while(temp->x != x and temp->next != NULL)
                {
                    temp=temp->next;
                }
                while(temp->y != y and temp->down != NULL)
                {
                    temp=temp->down;
                }
                temp->data = data;
                return;

            }

            if(x==0 or y==0){
                cout << "IllegalIndexPosition" << endl;
                throw;
            }
            if(x>columns or y>rows)
            {
                cout<< "OutOfRange"<<endl;
                throw;
            }
            else
            {

                auto *tempX = hColumns;
                auto *tempY = hRows;
                auto *nodo = new Node<T>;
                int x1 = 0;
                int y1 = 0;
                nodo->x = x;
                nodo->y = y;
                nodo->data = data;

                for(int xi=0; xi<=columns; xi++)
                {
                    if(tempX->x==nodo->x)
                    {
                        if(tempX->down==NULL)
                        {
                            tempX->down=nodo;
                        }

                        if(tempX->down->y>nodo->y)
                        {
                            nodo->down=tempX->down;
                            tempX->down=nodo;
                        }
                        else if(tempX->down->y<nodo->y)
                        {
                            while(tempX->down and tempX->y < nodo->y)
                            {
                                tempX = tempX->down;
                            }
                            tempX->down=nodo;
                        }
                        break;
                    }
                    if(tempX->next!=NULL)
                    {
                        tempX = tempX->next;
                    }
                }
                for(int yi=0; yi<=rows; yi++)
                {
                    if(tempY->y==nodo->y)
                    {
                        if(tempY->next==NULL)
                        {
                            tempY->next=nodo;
                        }

                        if(tempY->next->x>nodo->x)
                        {
                            nodo->next=tempY->next;
                            tempY->next=nodo;
                        }
                        else if(tempY->next->x<nodo->x)
                        {
                            while(tempY->next and tempY->x < nodo->x)
                            {
                                tempY = tempY->next;
                            }
                            tempY->next=nodo;
                        }

                        break;
                    }
                    if(tempY->down!=NULL)
                    {
                        tempY = tempY->down;
                    }

                }
                cout<<"Created node in"<<" "<<nodo->x<<" "<<nodo->y<<" with data: "<<nodo->data<<endl;
            }

        };
    T get(int x, int y)
    {
        if(x == 0 or y == 0)
        {
            cout<<"InvalidIndex"<<endl;
            throw;
        }
        else{
            auto *temp = hColumns;

            while(temp->x != x and temp->next != NULL)
            {
                temp=temp->next;
            }
            while(temp->y != y and temp->down != NULL)
            {
                temp=temp->down;
            }

            if(temp->x == x and temp->y == y)
            {
                return temp->data;
            }
            else
            {
                return 0;
            }
        }

    }
        T operator()(int x, int y)
        {
            if(x == 0 or y == 0)
            {
                cout<<"InvalidIndex"<<endl;
                throw;
            }
            else{
            auto *temp = hColumns;
         
            while(temp->x != x and temp->next != NULL)
            {
                temp=temp->next;
            }
            while(temp->y != y and temp->down != NULL)
            {
                temp=temp->down;
            }

             if(temp->x == x and temp->y == y)
             {
                return temp->data;
             }
             else
                 {
                 return 0;
                 }
            }
        };
        Matrix<T> operator*(Matrix<T> other){};
        Matrix<T> operator*(T scalar)
        {
            auto *temp = hColumns;
            for(int i=0; i<=columns; i++)
            {
                if(temp->next)
                {
                temp = temp->next;
                    for(int i=0; i<=rows;i++)
                    {
                        if(temp->down)
                        {
                            temp = temp->down;
                            temp->data *= scalar;
                        }
                    }
                }

            }
        };
        Matrix<T> operator+(Matrix<T> other)
        {
            if(columns < other.columns and rows < other.columns)
            {
                cout<<"InvalidMatrixB";
                throw;
            }
            else if (columns == other.columns and rows == other.rows){
            auto resultado = *this;
            auto *temp2 = other.hColumns;
            auto *temp1 = other.hColumns;
            for(int i=0; i<=other.columns; i++)
            {
                if(temp2->next)
                {
                    temp1= temp2->next;

                    for(int i=0; i<=other.rows;i++)
                    {

                        if(temp2->x != 0 and temp2->y != 0)
                        {
                            if(resultado(temp2->x, temp2->y) == NULL)
                            {
                                resultado.set(temp2->x, temp2->y, temp2->data);
                                temp2 = temp1;
                                break;
                            }
                            else
                            {
                                resultado.set(temp2->x,temp2->y,(temp2->data+resultado(temp2->x, temp2->y)));
                                temp2 = temp1;
                                break;
                            }

                        }
                        else if(temp2->down!=NULL and (temp2->x == 0 or temp2->y == 0))
                        {
                            temp2 = temp2->down;
                        }
                        else if(temp2->down == NULL)
                        {
                            temp2 = temp1;
                            break;
                        }

                    }
                }
            }
            return resultado;}
        };
        Matrix<T> operator-(Matrix<T> other){};
        Matrix<T> transposed(){};
        Matrix<T> operator=(Matrix<T> other){};
        T print()
        {
            for(int y = 1; y<=rows; y++)
            {
                for(int x=1; x<=columns; x++)
                {
                    cout<<get(x,y)<<" ";
                }
                cout<<endl;
            }
        }

        ~Matrix(){};
};

#endif
