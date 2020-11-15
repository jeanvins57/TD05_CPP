#include "Cell.h"
#include <fstream>
#include <iostream>

using namespace std;

Cell::Cell(int x, int y) : m_x(x), m_y(y)
{

}

Cell::~Cell()
{
  
}

// Q1. 
ostream & operator<<(ostream &stream, const Cell &c)
{
	stream << "(" << c.m_x << "," << c.m_y << ")";
	return stream;
}

void Cell::add_neighb(Cell *n1)
{
  for(int i = 0 ; i < m_nb_neighb ; i++)
    if(m_neighb[i] == n1)
      return;

  m_nb_neighb++;

  Cell **new_neighb = new Cell*[m_nb_neighb];
  for(int i = 0 ; i < m_nb_neighb - 1 ; i++)
    new_neighb[i] = m_neighb[i];

  new_neighb[m_nb_neighb - 1] = n1;
  delete[] m_neighb;
  m_neighb = new_neighb;

  n1->add_neighb(this);
}

void Cell::add_neighb(Cell *n1, Cell *n2)
{
  add_neighb(n1);
  add_neighb(n2);
}

void Cell::add_neighb(Cell *n1, Cell *n2, Cell *n3)
{
  add_neighb(n1);
  add_neighb(n2);
  add_neighb(n3);
}