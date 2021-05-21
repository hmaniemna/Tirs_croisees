#ifndef BOX_H
#define BOX_H
class Box
{
    public:
    int L,C,value; //each Box defined with line L,column C and his value
    Box();
    Box (int i,int j,int v);
    void changeval();
};
#endif // BOX_H
