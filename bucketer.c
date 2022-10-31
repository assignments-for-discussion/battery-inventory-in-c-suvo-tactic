#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  
  // loop begins from i=0 -> nBatteries-1

  for(int i=0;i<nBatteries;++i)
  {
      if(cycles[i]<410)counts.lowCount+=1;  // checks the status of Battery if it is less than 410 then Low is printed
      else if(cycles[i]>=410 && cycles[i]<=949)counts.mediumCount+=1;  // else if it is greater than 410  and less 949 than then Medium is printed
      else counts.highCount+=1; // else if it is greater than 950 than then High is printed
  }
  
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Done counting :)\n");
}

int main() {
  testBucketingByNumberOfCycles();
  return 0;
}
