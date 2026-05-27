#include <iostream>
#include <string>
using namespace std;


void HienThiMang(int mang[], int kichThuoc) {
    cout << " [ ";
    for (int i = 0; i < kichThuoc; i++) {
        cout << mang[i];
        if (i < kichThuoc - 1) cout << ", ";
    }
    cout << " ]\n";
}

void DieuChinhHeap(int mang[], int kichThuoc, int viTriGoc) {
    int viTriLonNhat = viTriGoc;
    int viTriConTrai = 2 * viTriGoc + 1;
    int viTriConPhai = 2 * viTriGoc + 2;

    // So sanh voi con trai
    if (viTriConTrai < kichThuoc && mang[viTriConTrai] > mang[viTriLonNhat]) {
        viTriLonNhat = viTriConTrai;
    }
    
    // So sang voi con phai
    if (viTriConPhai < kichThuoc && mang[viTriConPhai] > mang[viTriLonNhat]) {
        viTriLonNhat = viTriConPhai;
    }

    // TH can hoan doi
    if (viTriLonNhat != viTriGoc) {
        int tam = mang[viTriGoc];
        mang[viTriGoc] = mang[viTriLonNhat];
        mang[viTriLonNhat] = tam;
        DieuChinhHeap(mang, kichThuoc, viTriLonNhat); // de quy xuong duoi
    }
}

void XayDungHeap(int mang[], int kichThuoc) {
    for (int i = kichThuoc / 2 - 1; i >= 0; i--) {
        DieuChinhHeap(mang, kichThuoc, i);
        cout << "Heapify tai vi tri " << i + 1 << ":";
        HienThiMang(mang, kichThuoc);
    }
}


void HeapSort(int mang[], int kichThuoc) {
    int demBuoc = 1;
    for (int i = kichThuoc - 1; i > 0; i--) {
        // Hoan doi phan t dau voi phan tu cuoi
        int giaTriTam = mang[0];
        mang[0] = mang[i];
        mang[i] = giaTriTam;
        
        cout << "Buoc " << demBuoc << " (doi cho " << mang[0] << " voi " << mang[i] << "):";
        HienThiMang(mang, kichThuoc);
        
        DieuChinhHeap(mang, i, 0); // Vun dong phan con lai
        demBuoc++;
    }
}

int main() {
    
    int mangSlide[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n1 = sizeof(mangSlide) / sizeof(mangSlide[0]);

    cout << "BAI 1: MANG TU SLIDE\n";
    cout << "Mang ban dau:";
    HienThiMang(mangSlide, n1);
    
    cout << "\n CAC TRANG THAI VUN DONG \n";
    XayDungHeap(mangSlide, n1);
    
    cout << "\n CAC TRANG THAI SAP XEP \n";
    HeapSort(mangSlide, n1);
    
    cout << "\nMang sau khi sap xep tang dan:";
    HienThiMang(mangSlide, n1);


    cout << "\n\n BAI 2: MANG TREN BANG \n";
    int mangAnh[] = {11, 34, 32, 106, 38, 78, 203, 16, 84, 17, 39, 15};
    int n2 = sizeof(mangAnh) / sizeof(mangAnh[0]);

    cout << "Mang ban dau:";
    HienThiMang(mangAnh, n2);
    
    cout << "\n CAC TRANG THAI VUN DONG \n";
    XayDungHeap(mangAnh, n2);
    
    cout << "\n CAC TRANG THAI SAP XEP \n";
    HeapSort(mangAnh, n2);
    
    cout << "\nMang sau khi sap xep tang dan:";
    HienThiMang(mangAnh, n2);

    return 0;
}
