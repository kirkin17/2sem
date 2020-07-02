#include <iostream>
using namespace std;

struct tree 
{
   int key[3];
   int keys;
   struct tree* first; 
   struct tree* second;
   struct tree* third;
   struct tree* fourth;
   struct tree* parent;
};

struct tree* newend(int k) 
{
   tree* p = new tree;
   p->keys = 1;
   p->key[0] = k;
   p->key[1] = 0;
   p->key[2] = 0;
   p->first = NULL;
   p->second = NULL;
   p->third = NULL;
   p->fourth = NULL;
   p->parent = NULL;
   return p;
}

void sm(int* a, int* b) 
{
   int r = *a;
   *a = *b;
   *b = r;
}

void zam_1(tree* n, int k) 
{
   n->key[n->keys] = k;
   n->keys = n->keys + 1;
if (n->keys == 2)
if (&(n->key[0]) > & (n->key[1]))
   sm(&(n->key[0]), &(n->key[1]));
if (n->keys == 3) 
{
   if (&(n->key[0]) > & (n->key[1])) sm(&(n->key[0]), &(n->key[1]));
   if (&(n->key[0]) > & (n->key[2])) sm(&(n->key[0]), &(n->key[2]));
   if (&(n->key[1]) > & (n->key[2])) sm(&(n->key[1]), &(n->key[2]));
}
}

struct tree* newtree(int k, tree* k01, tree* k02, tree* k03, tree* k04, tree* parent0){
   tree* p = new tree;
   p->keys = 1;
   p->key[0] = k;
   p->key[1] = 0;
   p->key[2] = 0;
   p->first = k01;
   p->second = k02;
   p->third = k03;
   p->fourth = k04;
   p->parent = parent0;
   return p;
}

struct tree* branch(tree* t) 
{
   if (t->keys < 3) return t;
   struct tree* x = newtree(t->key[0], t->first, t->second, NULL, NULL, t->parent);
   struct tree* y = newtree(t->key[2], t->third, t->fourth, NULL, NULL, t->parent);
   if (x->first) x->first->parent = x;
   if (x->second) x->second->parent = x;
   if (y->first) y->first->parent = y;
   if (y->second) 
   {
      y->second->parent = y;
   }
   if (t->parent) 
   {
      zam_1(t->parent, t->key[1]);
   if (t->parent->first == t) 
      t->parent->first = NULL;
   else if (t->parent->second == t) 
      t->parent->second = NULL;
   else if (t->parent->third == t) 
      t->parent->third = NULL;
   if (t->parent->first == NULL)
   {
      t->parent->fourth = t->parent->third;
      t->parent->third = t->parent->second;
      t->parent->second = y;
      t->parent->first = x;
   }

   else if (t->parent->second == NULL) 
   {
      t->parent->fourth = t->parent->third;
      t->parent->third = y;
      t->parent->second = x;
   }

   else 
   {
      t->parent->fourth = y;
      t->parent->third = x;
   }

struct tree* tmp = t->parent;
   free(t);
   return tmp;
}

else 
{
   x->parent = t;
   y->parent = t;
   t->key[0] = t->key[1];
   t->first = x;
   t->second = y;
   t->third = NULL;
   t->fourth = NULL;
   t->parent = NULL;
   t->keys = 1;
   return t;
}
}

struct tree* zam(tree* p, int k) 
{
   if (!p) return newend(k);
   if ((p->first == NULL) && (p->second == NULL) && (p->third == NULL)) zam_1(p, k);
   else if (k <= p->key[0]) zam(p->first, k);
   else if ((p->keys == 1) || ((p->keys == 2) && k <= p->key[1])) zam(p->second, k);
   else zam(p->third, k);
   return branch(p);
}

void level(tree* ch1, int lv) 
{
   if (ch1 != NULL && lv == 0) 
   {
      if (ch1->parent)
      if (ch1->keys == 1) 
      {
         cout << ch1->key[0] << " Родитель [" << ch1->parent->key[0] << " " << ch1->parent->key[1] << "]" << endl;
      }
   else 
   {
      cout << ch1->key[0] << " " << ch1->key[1] << " Родитель [" << ch1->parent->key[0] << " " << ch1->parent->key[1] << "]";
   }
   else if (ch1->keys == 1) 
   {
      cout << ch1->key[0] << " корень" << endl;
   }
   else 
   {
      cout << ch1->key[0] << " " << ch1->key[1] << " корень";
   }
   }
   else if (ch1 != NULL) 
   {
      level(ch1->first, lv - 1);
      level(ch1->second, lv - 1);
      level(ch1->third, lv - 1);
   }

}

int main() 
{
setlocale(LC_ALL, "ru");
struct tree* tr = NULL;
int num;
cout << "Введите последовательность чисел: ";
   cin >> num;
while (num != 0) 
{
   if (!tr)
   tr = newend(num);
   else
   zam(tr, num);
   cin >> num;
}
for (int i = 0; i < 10; i++) 
{
   level(tr, i);
}
}