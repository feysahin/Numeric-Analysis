syms x;
f(x)=input('Fonksiyon:');                   %x^2-2*x-3
g(x)=input('g(x) fonksiyonu:');
h(x)=input('h(x) fonksiyonu:');
x1=input('Ilk x degeri:');
eps=input('Epsilon degeri:');
us=input('g fonksiyonunun kuvvetinin carpma islemine gore tersi:');

gt(x)=power(g(x),us);
ht(x)=power(h(x),us);

gt1(x)=diff(gt(x));
ht1(x)=diff(ht(x));

gtmutlak=abs(gt1(x1));
htmutlak=abs(ht1(x1));

if gtmutlak>htmutlak     
    kok1=ht(x1);
    fark=abs(x1-kok1);            
    
    fprintf('\nx1:\t\t\t\tkok1:\t\t\tmutlak fark:\n');
    fprintf('%f\t\t%f\t\t%f\n', x1, kok1, fark);
    
    while fark>eps
        x1=kok1;
        kok1=ht(kok1);
        fark=abs(x1-kok1);
        fprintf('%f\t\t%f\t\t%f\n', x1, kok1, fark);
    end
else
    fprintf('Yanlis fonksiyon secimi!');
end    
fprintf('\nYaklasik kok: %f', kok1);