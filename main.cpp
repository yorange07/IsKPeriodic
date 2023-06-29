//Эта программа демонстрирует работу функции проверки периодичности строки
#include <iostream>

bool IsKPeriodic (const std::string& s, int K);//Функция врзвращает 1, если строка s периодична К

int main()
{
    std::string str{"abcabcabc"};

    if (IsKPeriodic(str,3))
       std::cout << "Строка периодична" << std::endl;
    else std::cout << "Строка непериодична" << std::endl;

    return 0;
}

bool IsKPeriodic (const std::string& s, int K)
{
  bool res = true;
  std::string* pat_s = new std::string;//Для подстроки длиной K

  //Наполняем подстроку К первыми символами строки s
  for (int i = 0; i < K; i++)
      pat_s -> push_back(s[i]);

  int k = 0;//Счетчик по подстроке

  if (K <= s.size())//При условии, что К меньше или равно размеру строки s
  //Сравниваем посимвольно с подстрокой-паттерном все подстроки строки s, следующие за первой такой подстрокой
  for (int i = K; i < s.size() && res == true; i++)
  {
      if (s[i] != (*pat_s)[k])//При первом же несоотвествии получаем false
      {
          res = false;
      }
      else k++;

      if (i == s.size() - 1 && k != K)//При некратности по числу символов получаем false
          res = false;

      if (res == true && k == K)//При достижении последнего символа паттерна сбрасываем его счетчик
          k = 0;
  }
  else res = false;//При неккоректности К получаем false

  delete pat_s;
  return res;
};
