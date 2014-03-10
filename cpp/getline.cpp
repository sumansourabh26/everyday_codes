#include<simplecpp>


void
printCountries(char
countries[][4],
int
n){
for(int
i=0;
i<n;
i++)
cout
<<
countries[i]
<<"@"<<
endl;
}

main_program{
char
countries[3][4]={"qwe","rty","uio"};
printCountries(countries,
2);
}
