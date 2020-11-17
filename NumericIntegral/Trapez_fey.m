syms x;
f(x)=input('Fonksiyon:');
x_ilk=input('Ýlk x degeri: ');
x_son=input('Son x degeri: ');
n=input('n degeri: ');
toplam=0;
sayac=0;
if f(x_ilk)*f(x_son)<0
    kok=input('Kok: ');    
    sayac=1;
end
for i=0:sayac
    if sayac==0
        kok=x_son;
    end
    h=(kok-x_ilk)/n;
    toplam=toplam+(abs((f(x_ilk)+f(x_ilk+h)))*h)/2;
    for j=2:n
        x_ilk=x_ilk+h;
        toplam=toplam+(abs((f(x_ilk)+f(x_ilk+h)))*h)/2;
    end
    x_ilk=kok;
    kok=x_son;
end
fprintf('Trapez sonucu: %f: ', toplam);