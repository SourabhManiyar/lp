import alpaca_trade_api as tradeapi
import warnings

warnings.filterwarnings('ignore')

SEC_KEY = ''  # Enter Your Secret Key Here
PUB_KEY = ''  # Enter Your Public Key Here
BASE_URL = 'https://paper-api.alpaca.markets'  # This is the base URL for paper trading
api = tradeapi.REST(
    key_id=PUB_KEY, secret_key=SEC_KEY, base_url=BASE_URL,
    api_version='v2')  # For real trading, don't enter a base_url


def buy(q, s):  # Returns nothing, makes call to buy stock
    api.submit_order(symbol=s,
                     qty=q,
                     side='buy',
                     type='market',
                     time_in_force='gtc')

    return "Total number of quantity bought is {}".format(q)


def sell(q, s):  # Returns nothing, makes call to sell stock
    api.submit_order(symbol=s,
                     qty=q,
                     side='sell',
                     type='market',
                     time_in_force='gtc')
    return "Total number of quantity sold is {}".format(q)


def check_price(symb, hours_to_test):
    print("Checking Price")
    market_data = api.get_barset(
        symb, 'minute',
        limit=(60 *
               hours_to_test))  # Pull market data from the past 60x minutes

    close_list = []
    for bar in market_data[symb]:
        close_list.append(bar.c)

    print("Open: " + str(close_list[0]))
    print("Close: " + str(close_list[60 * hours_to_test - 1]))


naam = input("Enter your name: ")
print("Hello! How may I help you, {}?".format(naam))
print("To continue please choose from the following")

while 1:
    print("-----Menu-----")
    print("1) Check Price")
    print("2) Buy")
    print("3) Sell")
    print("4) Account details")
    print("5) Get your Position for specific company")
    print("6) Exit")
    ch = int(input("Enter your choice: "))
    if ch == 1:
        print("\n")
        stock_name = input("Enter the stock name: ")
        htt = int(input("Enter the hours to test(duration): "))
        check_price(stock_name, htt)
        print("\n")
    elif ch == 2:
        print("\n")
        stock_name = input("Enter the stock name: ")
        quant = int(input("Enter the quantity to buy: "))
        try:
            buy(quant, stock_name)
        except:
            print("Unable to buy it now. Try agai later.")
        print("\n")
    elif ch == 3:
        print("\n")
        stock_name = input("Enter the stock name: ")
        quant = int(input("Enter the quantity to sell: "))
        try:
            sell(quant, stock_name)
        except:
            print("The stock can't be sold !")
        print("\n")
    elif ch == 4:
        acc = api.get_account()
        print("\n")
        print("Equity: ", acc.equity)
        print("Buying Power: ", acc.buying_power)
        print("Last Equity: ", acc.last_equity)
        print("Long Market Value: ", acc.long_market_value)
        print("\n")
    elif ch == 5:
        print("\n")
        try:
            stc_name = input("Stock name: ")
            position = api.get_position(stc_name)
            print("Average Buying price: ", position.avg_entry_price)
            print("Current price: ", position.current_price)
            print("Quatity: ", position.qty)
            print("Today's P/L($): ", position.unrealized_intraday_pl)
            print("Today's P/L(%): ", position.unrealized_intraday_plpc)
            print("Total P/L($): ", position.unrealized_pl)
            print("Total P/L(%): ", position.unrealized_plpc)
        except:
            print("You don't have this stock!")
        print("\n")
    elif ch == 6:
        print("\n")
        print("Thank you! Visit Again.")
        break
    else:
        print("Please choose from the following:")