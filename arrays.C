
std::vector<float> fillVector( float array[], int size ) {

    std::vector<float> tmp;

    for(unsigned int i = 0; i < size; i++)
        tmp.push_back(array[i]);

    return tmp;

}


int fillArray( float array[] ) {

//  cout << " local array " << &array[0] <<endl;
    int i = 0;
    while(i != 10000) {
        array[i] = i;
        i++;
    }

    return i;
}


void arrays() {

    // Hay estaticos y dinamicos

// float My_array[5] = {0.};

// float My_array[] = {0.,3.14,6.32,4.59};

    float My_array[10000];

    cout << " local array " << &My_array[0] <<endl;

    int size = fillArray(My_array);

    std::vector<float> Myvector;

    Myvector = fillVector(My_array, size);

    cout << Myvector.size() << endl;


    TH1D *h1 = new TH1D( "h1","h1", 50, 0., 2.);
    string label = "momentuom";
    h1->SetTitle(label.c_str());

}

int main() {
    arrays();
    return 0;
}

