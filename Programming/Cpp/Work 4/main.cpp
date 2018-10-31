#include <map>
#include "Currency.h"
#include "parser/Parser.h"

using namespace tinyxml2;
using namespace std;

map<string, string> convertArgsIntoMap(int argc, char **argv) {
    map<string, string> args;

    for (int i = 1; i < argc; i++) {
        string currentArg = string(argv[i]);
        size_t position = currentArg.find('='); // position of symbol `=`

        string argName = currentArg.substr(2, position - 2); // get argument name without double `-`

        string argValue = currentArg.substr(position + 1); // get rest as argument value

        args.insert(pair<string, string>(argName, argValue));
    }

    return args;
}

Currency getCurrencyByCode(vector<Currency> currencies, string targetCurrencyCode) {
    for (auto currency : currencies) {
        if (currency.getCode() == targetCurrencyCode) {
            return currency;
        }
    }
}


int main(int argc, char *argv[]) {
    map<string, string> args = convertArgsIntoMap(argc, argv);

    // Get values from arguments
    string filename = args["data"];
    string fromCurrencyCode = args["from"];
    string toCurrencyCode = args["to"];

    vector<Currency> currencies = Parser::getCurrencies(filename);

    Currency fromCurrency = getCurrencyByCode(currencies, fromCurrencyCode);
    Currency toCurrency = getCurrencyByCode(currencies, toCurrencyCode);
    Currency convertedCurrency = fromCurrency.convert(toCurrency);

    cout << fromCurrency.getCode() << " : " << toCurrency.getCode() << " " << convertedCurrency.getCourse()
         << endl;

    return EXIT_SUCCESS;
}