syms x;
f(x)=input('Fonksiyon: ');                %x^3-13*x^2+52*x-60
eps=input('Epsilon degeri: ');
x_left=input('Ilk x degeri: ');
x_right=input('Son x degeri: ');    
if f(x_left)*f(x_right)<0
  x_center = (x_left + x_right)/2;
  center=abs(f(x_center));
  fark=abs(x_left - x_right);
  
  fprintf('\nx_left:\t\tf(x_left):\t\t x_right:\tf(x_right):\t\tx_center:\tf(x_center):\n');
  fprintf('%f\t%f\t\t %f\t %f\t\t %f\t %f\n', x_left, f(x_left), x_right, f(x_right), x_center, f(x_center));
  
  while fark>eps && center>eps
      if f(x_center)*f(x_left)<0
          x_right=x_center;
      else 
          x_left=x_center;
      end      
      x_center = (x_left + x_right)/2;
      fark=abs(x_left - x_right);
      
      fprintf('%f\t%f\t\t %f\t %f\t\t %f\t %f\n', x_left, f(x_left), x_right, f(x_right), x_center, f(x_center));
  end
else
    fprintf('Arada kok olmayabilir.');
end
fprintf('\nYaklasik kok: %f', x_center);