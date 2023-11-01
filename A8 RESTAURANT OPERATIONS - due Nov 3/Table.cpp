#include "Table.h"
#include "Order.h"
#include <iostream>
#include <sstream>

using namespace std;

Table::Table(int tableId, int capacity)
{
  this->tableId = tableId;
  this->capacity = capacity;
  this->partySize = 0;
  this->status = TableStatus::IDLE;
  this->orderp = nullptr;
}

bool Table::seatParty(int numGuests)
{
  if (status == TableStatus::IDLE) {
    if (numGuests <= capacity)
    {
      partySize = numGuests;
      status = TableStatus::SEATED;
      return true;
    } else {
      cout << "Sorry, max " << capacity << " seats in Table " << tableId << "!" << endl;
      return false;
    }
  } else {
    cout << "Table " << tableId << " already occupied!" << endl;
    return false;
  }
}

bool Table::placeOrder(std::string str, Menu *menup)
{
  istringstream istr(str);
  string menuCode;
  int orderCount = 0;

  if (status == TableStatus::SEATED) {
    orderp = new Order(str, menup);
    while (istr >> menuCode) {
      if (orderp->addItems(menuCode, menup)) {
        orderCount++;
      }
    }
    cout << orderCount << " items ordered for Table " << tableId << endl;
    status = TableStatus::ORDERED;
  } else {
    while (istr >> menuCode) {
      if (orderp->addItems(menuCode, menup)) {
        orderCount++;
      }
    }
    cout << orderCount << " additional items ordered for Table " << tableId << endl;
  }
  return true;
}

bool Table::serve()
{
  if (status == TableStatus::ORDERED)
  {
    status = TableStatus::SERVED;
    return true;
  }
  return false;
}

bool Table::cleanup()
{
  if (status == TableStatus::SERVED)
  {
    partySize = 0;
    status = TableStatus::IDLE;
    orderp->printReceipt(tableId, capacity);
    if (orderp != nullptr)
    {
      delete orderp;
      orderp = nullptr;
    }
    return true;
  }
  return false;
}

int Table::getCapacity() {
  return capacity;
}

Table::~Table()
{
  if (orderp != nullptr)
  {
    delete orderp;
  }
}
