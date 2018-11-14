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
            for(int x=2; x<=sizeX; x++)
            {
                auto *temp = new Node<T>;

                temp->x=x;
                temp->y=0;
                temp->data=x;
                tempn->next=temp;
                tempn = temp;
            }
            for(int y=2; y<=sizeY; y++)
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
            /*if(data==0)
            {

                auto *temp = hColumns;
                auto *temp1 = hColumns;
                auto *temp2 = hRows;
                auto *temp3 = hColumns;

                while(temp3->x != x and temp3->next != NULL)
                {
                    temp3=temp3->next;
                }
                while(temp3->y != y and temp3->down != NULL)
                {
                    temp3=temp3->down;
                }

                if(temp3->next == NULL and temp3->down == NULL){cout<<"Nodo no existe, no se hizo nada"<<endl;}

                while(temp1->x != x and temp1->next != NULL)
                {
                    temp1=temp1->next;
                }
                while(temp1->down->y != y and temp1->down != NULL){temp1 = temp1->down;}
                if(temp1->down->down)
                {
                    temp = temp1->down;
                    temp1->down = temp1->down->down;
                }
                else{temp1->down = NULL;}
                while(temp2->y != y and temp2->down != NULL)
                {
                    temp2=temp2->down;
                }
                while(temp2->next->x != x and temp2->next != NULL){temp2 = temp2->next;}
                if(temp2->next->next)
                {
                    temp = temp2->next;
                    temp2->next = temp2->next->next;
                }else{temp2->next = NULL;}
                    cout<<"Nodo "<<temp->x<<" "<<temp->y<<" borrado"<<endl;
                    delete temp;
                    return;

            }*/

            if(data==0){return;}

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
        Matrix<T> operator*(Matrix<T> other)
        {
            if(rows == other.columns or other.rows == columns){
            auto C = Matrix(other.columns, rows);
            int data;
            for(int c=1; c <= rows; c++)
            {
                for (int i = 1; i <= other.columns; i++)
                {
                    data = 0;
                    for (int j = 1; j <= columns; j++)
                    {
                        data += other(c,j) * get(j,i);
                    }
                    C.set(c,i,data);
                }
            }
            return C;}
            else
            {
                cout<<"InvalidMatrixes";
                throw;
            }
        };
        Matrix<T> operator*(T scalar)
        {
            auto C = Matrix(columns, rows);
            for(int y = 1; y<=rows; y++)
            {
                for(int x=1; x<=columns; x++)
                {
                    int data = get(x,y)*scalar;
                    C.set(x,y,data);

                }


            }return C;
        };
        Matrix<T> operator+(Matrix<T> other)
        {
            if(columns < other.columns and rows < other.columns)
            {
                cout<<"InvalidMatrixB";
                throw;
            }
            else if (columns == other.columns and rows == other.rows)
            {
                auto C = Matrix(columns, rows);
                for(int y = 1; y<=rows; y++)
                {
                    for(int x=1; x<=columns; x++)
                    {
                        int data = get(x,y)+other.get(x,y);
                        C.set(x,y,data);

                    }

                }return C;
            }
        };
        Matrix<T> operator-(Matrix<T> other)
        {
            if(columns < other.columns and rows < other.columns)
            {
                cout<<"InvalidMatrixB";
                throw;
            }
            else if (columns == other.columns and rows == other.rows)
            {
                auto C = Matrix(columns, rows);
                for(int y = 1; y<=rows; y++)
                {
                    for(int x=1; x<=columns; x++)
                    {
                        int data = get(x,y)-other.get(x,y);
                        C.set(x,y,data);

                    }

                }return C;
            }

        };
        Matrix<T> transposed()
        {
            auto C = Matrix(rows,columns);
            auto *temp = hColumns;
            auto *temp1 = hColumns;
            while(temp)
            {
                temp1 = temp->next;
                if(temp->down)
                {
                    while(temp->down){
                    temp = temp->down;
                    if(temp->x!=0 and temp->y!=0){
                    C.set(temp->y, temp->x, temp->data);}}
                    temp = temp1;
                }
                else{temp = temp1;}
            }return C;

        };
        Matrix<T> operator=(Matrix<T> other)
        {
            for (int y = 1; y <= rows; y++) {
                for (int x = 1; x <= columns; x++) {
                    set(x,y,0);}}
            if( rows == other.rows and columns == other.columns) {
                for (int y = 1; y <= rows; y++) {
                    for (int x = 1; x <= columns; x++) {
                        int data = other.get(x, y);
                        set(x, y, data);

                    }

                }
            }
            else
            {
                cout<<"No se puede igualar";
                throw;
            }

        };
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
