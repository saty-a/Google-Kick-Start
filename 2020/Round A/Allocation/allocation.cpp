// Usage: cat input.txt | ./applicationName

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    unsigned int numTestCases(0);

    unsigned int count(scanf("%d", &numTestCases));
    if (count != 1) {
        std::printf("Too few test cases!\n");
        return -1;
    }

    std::vector<unsigned int> numHousesBuyable;
    for (unsigned int testCase = 0; testCase < numTestCases; testCase++) {
        unsigned int numHouses(0), budget(0);
        count = scanf("%d %d", &numHouses, &budget);
        if (count != 2) {
            std::printf("Num houses and/or budget not specified!\n");
            return -1;
        }
        std::vector<unsigned int> housePrices;
        unsigned int housePrice(0);
        for (unsigned int j = 0; j < numHouses; j++) {
            count = scanf("%d ", &housePrice);
            if (count != 1) {
                std::printf("Not enough house prices for the test case %d!\n", testCase);
                return -1;
            }
            housePrices.push_back(housePrice);
        }

        std::sort(housePrices.begin(), housePrices.end());

        unsigned int currPrice(0);
        for (size_t priceIndex = 0; priceIndex < housePrices.size(); priceIndex++) {
            currPrice += housePrices[priceIndex];
            if (currPrice > budget) {
                numHousesBuyable.push_back(priceIndex);
                break;
            } else if (currPrice == budget) {
                numHousesBuyable.push_back(priceIndex + 1);
                break;
            }
        }
    }

    std::printf("Detected %d test cases\n", numTestCases);
    for (size_t testCase = 0; testCase < numHousesBuyable.size(); testCase++) {
        std::printf("Case %ld: %d\n", testCase + 1, numHousesBuyable[testCase]);
    }
    return 0;
}
