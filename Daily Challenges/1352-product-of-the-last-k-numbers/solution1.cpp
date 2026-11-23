class ProductOfNumbers {
public:
    vector<int>product;
    ProductOfNumbers() {
        product.push(1);
    }
    
    void add(int num) {
        if(num==0){
            product.clear();
            product.push(1);
        }
        else{
            product.push_back(product.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n=product.size();
        if(k>=n)return 0;
        return product[n-1]/product[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */