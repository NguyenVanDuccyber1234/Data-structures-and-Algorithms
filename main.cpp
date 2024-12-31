#include <iostream>
#include <math.h>
using namespace std;

// 1.Tạo mảng số thực có các giá trị sau: |0.8|5.6|9.1|7.3|10|5.9|7.2| 9.3|8.0|8.7|

void TaoMang1D (float* a , int* n)
{
    *n = 10;
    *(a+0) = 0.8;
    *(a+1) = 5.6;
    *(a+2) = 9.1;
    *(a+3) = 7.3;
    *(a+4) = 10;
    *(a+5) = 5.9;
    *(a+6) = 7.2;
    *(a+7) = 9.3;
    *(a+8) = 8.0;
    *(a+9) = 8.7;
}

//2.Xuất mảng ra màn hình.

void XuatMang1D (float* a , int* n)
{
    for (int i = 0; i < *n ; i++)
    {
        printf("%0.1f ",*(a+i));
    }
}

// 3.Kiểm tra mảng có toàn dương.

int KtraToanDuong (float* a , int* n)
{
    for (int i = 0; i < *n ; i++)
    {
        if (*(a+i) < 0)
            return false;
    }
    return true;
}

//6.Kiểm tra mảng có đối xứng.

int KtraDoiXung (float* a , int* n)
{
    for (int i = 0; i < *n/2 ; i++)
    {
        if (*(a+i) != *(a+(*n-i-1)))
            return false;
    }
    return true;
}

//7.Kiểm tra trong mảng có số nguyên tố, số chính phương.

int KiemTraSoChinhPhuong(float*a , int*n)
{
    int sqr;
    for (int i = 0 ; i < *n ; i++)
    {
        sqr = sqrt(*(a+i));
        if(sqr*sqr == *(a+i))
            return true;
    }
    return false;
}
//8.Tìm một giá trị trong mảng.

int KTraGiaTri (float* a , int* n, float* t)
{
    for (int i = 0 ; i < *n ; i++)
    {
        if(*(a+i) == *t)
            return true;
    }
    return false;
}

//10.Tìm số chính phương có trong mảng.

void TimSoChinhPhuong (float*a , int*n)
{
    int sqr;
    if(KiemTraSoChinhPhuong(a,n))
        cout << endl << "So chinh phuong trong mang la ";
    else
        cout << "";
    for (int i = 0 ; i < *n ; i++)
    {
        sqr = sqrt(*(a+i));
        if(sqr*sqr == *(a+i))
            cout << *(a+i) << "\t";
    }
}

//11.Trả về các số âm trong mảng.

void TraVeGTriAm (float* a , int* n)
{
    bool GiaTriAm = false;
    for(int i = 0 ; i < *n ; i++)
    {
        if (*(a+i) < 0)
            {
                if(!GiaTriAm)
                    {
                        cout << endl <<"Cac gia tri am là ";
                        GiaTriAm = true;
                    }
                cout << *(a+i) << " ";
            }
    }
    if (!GiaTriAm)
        cout << endl << "Mang khong co gia tri am";
}

//12.Trả về các số dương trong mảng và tổng của chúng.

void TraVeGTriDuongvaTinhTong (float* a , int* n)
{
    float tong = 0.0;
    bool GiaTriDuong = false;
    for(int i = 0 ; i < *n ; i++)
    {
        if (*(a+i) > 0)
            {
                tong = tong + *(a+i);
                if(!GiaTriDuong)
                    {
                        cout << endl <<"Cac gia tri duong la ";
                        GiaTriDuong = true;
                    }
                printf("%0.1f ",*(a+i));;
            }
    }
    if (!GiaTriDuong)
        cout << endl << "Mang khong co gia tri duong";

    printf("\nTong gia tri duong la %0.1f",tong);
}

//13.Đảo Ngược các Phần tử trong mảng.

void DaoNguoc(float* a , int* n,int* start, int* end)
{
    while(*start < *end)
    {
        float temp = *(a+*start);
        *(a+*start) = *(a+*end);
        *(a+*end) = temp;
        *start = *start + 1;
        *end = *end -1 ;
    }
    printf("\nMang Da Dao Nguoc la: ");
    for(int i = 0 ; i < *n ; i++)
    {
        printf("%0.1f ",*(a+i));
    }
}


int main()
{
    float* a = new float[10];
    int* n = new int(0);

    // 1.Tạo mảng số thực có các giá trị sau: |0.8|5.6|9.1|7.3|10|5.9|7.2| 9.3|8.0|8.7|

    TaoMang1D (a,n);

    //2.Xuất mảng ra màn hình.

    XuatMang1D(a,n);

    // 3.Kiểm tra mảng có toàn dương.

    if(KtraToanDuong(a,n))
        printf("\nMang Toan Gia Tri Duong");
    else
        printf("\nMang Toan Co Gia Tri Am");

    //6.Kiểm tra mảng có đối xứng.

    if(KtraDoiXung(a,n))
        printf("\nMang Doi Xung");
    else
        printf("\nMang Khong Doi Xung");

    //7.Kiểm tra trong mảng có số nguyên tố, số chính phương.

    if(KiemTraSoChinhPhuong(a,n))
        cout << endl << "Mang co so chinh phuong";
    else
        cout << endl << "Mang khong co so chinh phuong";

    //8.Tìm một giá trị trong mảng.

    float* t = new float;
    cout << "\nNhap gia tri t = ";
    cin >> *t;
    if(KTraGiaTri(a,n,t))
        cout << *t << " tim thay trong mang";
    else
        cout << *t << " khong tim thay trong mang";

    //10.Tìm số chính phương có trong mảng.

    TimSoChinhPhuong(a,n);

    //11.Trả về các số âm trong mảng.

    TraVeGTriAm(a,n);

    //12.Trả về các số dương trong mảng và tổng của chúng.

    TraVeGTriDuongvaTinhTong(a,n);

    //13.Đảo Ngược các Phần tử trong mảng.

    int* start = new int (0);
    int* end = new int (*n-1);
    DaoNguoc(a,n,start,end);
}
