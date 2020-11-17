syms x;
f(x)=input('Fonksiyon:');
x0=input('Ýlk x degeri: ');
xn=input('Son x degeri: ');
n=input('n degeri: ');
sayac=0;
toplam=0;
if f(x0)*f(xn)<0
    kok=input('Kok: ');    
    sayac=1;
end
for i=0:sayac
    h=(kok-x0)/n;
    x1=x0+h;
    toplam=toplam+(abs((f(x1-h)+4*f(x1)+f(x1+h)))*h)/3;

    for j=2:n/2
        x1=x1+2*h;
        toplam=toplam+(abs((f(x1-h)+4*f(x1)+f(x1+h)))*h)/3;
    end
    x0=kok;
    kok=xn;
end   
fprintf('Simpson sonucu: %f: ', toplam);