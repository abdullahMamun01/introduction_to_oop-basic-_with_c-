// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    int total_prices;

protected:
    int total_tax;

public:
    Restaurant()
    {
        this->total_tax = 0;
    }

public:
    int is_valid_code(int food_item_codes)
    {
        int is_valid = 0;
        for (int i = 0; i < 12; i++)
        {
            if (this->food_item_codes[i] == food_item_codes)
            {
                is_valid = 1;
                break;
            }
        }
        return is_valid;
    }
    friend class Resutrent_Bill;
};

class Resutrent_Bill
{
public:
    void food_order_list(int items, int order_list[][2], Restaurant *restaurant)
    {
        int total_price = 0;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < items; j++)
            {
                if (restaurant->food_item_codes[i] == order_list[j][0])
                {

                    cout << setw(20) << left << restaurant->food_item_codes[i];
                    cout << setw(35) << left << restaurant->food_item_names[i];
                    cout << setw(20) << left << restaurant->food_item_prices[i];
                    cout << setw(20) << left << order_list[j][1];
                    cout << setw(20) << left << restaurant->food_item_prices[i] * order_list[j][1] << endl;
                    total_price += (restaurant->food_item_prices[i] * order_list[j][1]);
                }
            }
        }
        restaurant->total_tax = (total_price * 5) / 100;
        restaurant->total_prices = restaurant->total_tax + total_price;
        cout << setw(95) << left << "Tax ";
        cout << setw(20) << left << restaurant->total_tax << endl;
    }
};

Restaurant *generate_resturent_items(int n)
{
    Restaurant *resturent = new Restaurant();
    for (int i = 0; i < n; i++)
    {
        cin >> resturent->food_item_codes[i];
        getchar();
        getline(cin, resturent->food_item_names[i]);
        cin >> resturent->food_item_prices[i];
    }
    return resturent;
}

void display_resturent_items(int n, Restaurant *resturent)
{
    cout << right << setw(50) << "MAKE BILL" << endl;
    cout << right << setw(60) << "_________________________________" << endl;

    cout << setw(30) << left << "Item code";
    cout << setw(40) << left << "Item Name";
    cout << setw(30) << left << "Item Price" << endl
         << endl;
    for (int i = 0; i < n; i++)
    {

        cout << setw(30) << resturent->food_item_codes[i];
        cout << setw(40) << resturent->food_item_names[i];
        cout << setw(30) << resturent->food_item_prices[i] << endl;
    }
}

void order_list_from_user(int order_lis[][2], int total_items, Restaurant *resturent)
{

    for (int i = 0; i < total_items; i++)
    {
    FLAG:
        cout << "Enter item " << i + 1 << " Code : ";

        cin >> order_lis[i][0];

        if (!(resturent->is_valid_code(order_lis[i][0])))
        {
            cout << "Invalid code please enter again" << endl;
            goto FLAG;
        }

        cout << "Enter item " << i + 1 << " Quantity : ";
        cin >> order_lis[i][1];
    }
}

void bill_header(int table_no)
{
    cout << right << setw(65) << "BILL SUMMERY" << endl;
    cout << setw(70) << "___________________________" << endl;
    cout << "Table No: " << table_no << endl;
    cout << setw(20) << left << "Item code";
    cout << setw(35) << left << "Item name";
    cout << setw(20) << left << "Item price";
    cout << setw(20) << left << "Itme Quantity";
    cout << "Item Price" << endl;
}

void bill_footer(int total_price)
{
    cout << "_________________________________________________________________________________________________________" << endl;
    cout << setw(95) << left << "Net Total";
    cout << total_price << "  Taka" << endl;
}

int main()
{
    int n;
    cin >> n;
    Restaurant *resturent = generate_resturent_items(n);
    Resutrent_Bill *resturent_bill = new Resutrent_Bill;
    cout << endl;
FLAG:
    while (true)
    {
        display_resturent_items(n, resturent);

        cout << endl
             << endl
             << endl
             << endl;
        int table_number, total_items;
        cout << "Enter Table number : ";
        cin >> table_number;
        cout << "Enter number of items : ";
        cin >> total_items;
        int order_lis[total_items][2];
        order_list_from_user(order_lis, total_items, resturent);
        bill_header(table_number);
        resturent_bill->food_order_list(total_items, order_lis, resturent);
        bill_footer(resturent->total_prices);
    }
    goto FLAG;
    return 0;
}