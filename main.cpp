#include <iostream>
#include <iomanip>
using namespace std;
class fishbucket
{
  int count;
  double size[1000];
  string species;

public:
  fishbucket() {}
  fishbucket(string sp)
  {
    species = sp;
    count = 0;
  }
  string getspecies();
  int getcount();
  double getsmallestsize();
  double getlargestsize();
  double getaveragesize();
  void addcatch(double);
  void addbucket(fishbucket &, double);
};
int main()
{
  double length;
  int type;
  fishbucket bluegill("bluegill"),
      crappie("crappie"),
      walleye("walleye"),
      small_mouth_bass("small_mouth_bass"),
      mixed("mixed");
  for (int i = 0; i < 1000; i++)
  {
    cout << "enter size and species number 1 for bluegill,2 for crappie,"
            "3 for walleye,4 for small_mouth_bass and else for none"
         << endl;
    cin >> length >> type;
    if (type == 1)
      mixed.addbucket(bluegill, length);
    else if (type == 2)
      mixed.addbucket(crappie, length);
    else if (type == 3)
      mixed.addbucket(walleye, length);
    else if (type == 4)
      mixed.addbucket(small_mouth_bass, length);
    else
    {
    }
  }
  cout << setw(17) << "species" << setw(17) << "count" << setw(17) << "largest" << setw(17) << "smallest" << setw(17) << "average" << endl
       << "_______________________________________________________________________________" << endl
       << setw(17) << bluegill.getspecies()
       << setw(17) << bluegill.getcount()
       << setw(17) << bluegill.getlargestsize()
       << setw(17) << bluegill.getsmallestsize()
       << setw(17) << bluegill.getaveragesize() << endl
       << setw(17) << crappie.getspecies()
       << setw(17) << crappie.getcount()
       << setw(17) << crappie.getlargestsize()
       << setw(17) << crappie.getsmallestsize()
       << setw(17) << crappie.getaveragesize() << endl
       << setw(17) << walleye.getspecies()
       << setw(17) << walleye.getcount()
       << setw(17) << walleye.getlargestsize()
       << setw(17) << walleye.getsmallestsize()
       << setw(17) << walleye.getaveragesize() << endl
       << setw(17) << small_mouth_bass.getspecies()
       << setw(17) << small_mouth_bass.getcount()
       << setw(17) << small_mouth_bass.getlargestsize()
       << setw(17) << small_mouth_bass.getsmallestsize()
       << setw(17) << small_mouth_bass.getaveragesize() << endl
       << "===============================================================================" << endl
       << setw(17) << mixed.getspecies()
       << setw(17) << mixed.getcount()
       << setw(17) << mixed.getlargestsize()
       << setw(17) << mixed.getsmallestsize()
       << setw(17) << mixed.getaveragesize();

  return 0;
}
string fishbucket::getspecies()
{
  return species;
}
int fishbucket::getcount()
{
  return count;
}
double fishbucket::getsmallestsize()
{
  double smallest = size[0];
  for (int i = 0; i < count; i++)
  {
    if (size[i] < size[0])
    {
      smallest = size[i];
    }
  }
  return smallest;
}
double fishbucket::getlargestsize()
{
  double largest = size[0];
  for (int i = 0; i < count; i++)
  {
    if (size[i] > size[0])
    {
      largest = size[i];
    }
  }
  return largest;
}
double fishbucket::getaveragesize()
{
  double average, sum = 0;
  for (int i = 0; i < count; i++)
  {
    sum += size[i];
  }
  average = sum / count;
  return average;
}
void fishbucket::addcatch(double length)
{
  size[count] = length;
  count++;
}
void fishbucket::addbucket(fishbucket &bucket, double length)
{
  addcatch(length);
  bucket.addcatch(length);
}