/** ------------------------------------------------------------
 * Copyright (c) 2021 Phuc Nguyen
 *
 * $Author:             Phuc Nguyen
 * $Date:               September 18, 2021
 * $Version:            1.0.0
 *
 * File:                link_list.h
 * Project:             Learning data structures
 * -------------------------------------------------------------
 * Brief:
 *      Single list, doubly list, circular list:
 *          1.  Add:        Add a brand new node
 *          2.  Insert:     Insert a existing node
 *          3.  Search:     Search a existing node
 *          4.  Delete:     Delete a existing node
**/
#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H









/* -----------------------------------------------------------------------------
/* Include libraries
/*
/* -------------------------------------------------------------------------- */
#include <iostream.h>









/* -----------------------------------------------------------------------------
/* Macro definition
/*
/* -------------------------------------------------------------------------- */

#ifndef nullptr
#define nullptr 0
#endif









/* -----------------------------------------------------------------------------
/* Type definition
/*
/* -------------------------------------------------------------------------- */
typedef enum
{
    // The earlier node, the farther head
    STACK       =   0,

    // The ealier node, the closer head
    QUEUE       =   1,

} addMode_t;


// Error when using delete functions
typedef enum
{
    // Function doesn't run (delete 0 node)
    E_DEL_NUM   = 0,

    // Function is ok
    E_DEL_OK    = 1,

    // Head of list is nullptr
    E_DEL_HEAD  = 2,

    // Tail of list is nullptr
    E_DEL_TAIL  = 3,

    // Position > number of nodes
    E_DEL_POS   = 4,

    // All nodes are deleted, but num input > number of nodes
    W_DEL_NUM   = 5,

} errDel_t;


// Error when using insert functions
typedef enum
{

    // Function is ok
    E_INS_OK    = 1,

    // Head of list is nullptr
    E_INS_HEAD  = 2,

    // Tail of list is nullptr
    E_INS_TAIL  = 3,

    // Position > number of nodes
    E_INS_POS   = 4,

    // New node is nullptr
    E_INS_NEW_NODE = 6,

} errIns_t;









/* -----------------------------------------------------------------------------
/* Extern variables
/*
/* -------------------------------------------------------------------------- */









/* -----------------------------------------------------------------------------
/* Extern class
/*
/* -------------------------------------------------------------------------- */


template <class data_t>
class singleList_t
{

    // Variables
    private:
        singleList_t *ptr_next_;

    public:
    data_t  data_;


    // Get functions
    public:
        singleList_t *get_next();


    // Set functions
    public:
        void set_next(singleList_t *ptr_next);


    // Function protocols
    public:

        singleList_t();

};









/* -----------------------------------------------------------------------------
/* Extern functions template protocols
/*
/* -------------------------------------------------------------------------- */

template <class data_t>
singleList_t<data_t> *create_List(singleList_t<data_t> *&head, unsigned num = 1);

template <class data_t>
void traverse_List(singleList_t<data_t> *head, void (*subTask)(data_t &data_));

template <class data_t>
void arrange_List(singleList_t<data_t> *head, bool (*conTask)(data_t data1_, data_t data2_));




template <class data_t>
singleList_t<data_t> *get_Tail(singleList_t<data_t> *head);

template <class data_t>
int get_Index(singleList_t<data_t> *head, bool (*conTask)(data_t data_));

template <class data_t>
singleList_t<data_t> *get_Node(singleList_t<data_t> *head, unsigned pos = 0);

template <class data_t>
singleList_t<data_t> *find_Node(singleList_t<data_t> *head, bool(*conTask)(data_t data_), unsigned from = 0);




template <class data_t>
singleList_t<data_t> *add_Head(singleList_t<data_t> *&head, unsigned num = 1, addMode_t addMode = QUEUE);

template <class data_t>
singleList_t<data_t> *add_Tail(singleList_t<data_t> *&tail, unsigned num = 1);

template <class data_t>
singleList_t<data_t> *add_Before(singleList_t<data_t> *&head, unsigned num = 1, unsigned pos = 0, addMode_t addMode = QUEUE);

template <class data_t>
singleList_t<data_t> *add_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0);




template <class data_t>
errIns_t insert_Head(singleList_t<data_t> *&head, singleList_t<data_t> *newNode);

template <class data_t>
errIns_t insert_Tail(singleList_t<data_t> *&tail, singleList_t<data_t> *newNode);

template <class data_t>
errIns_t insert_Before(singleList_t<data_t> *&head, singleList_t<data_t> *newNode, unsigned pos = 0);

template <class data_t>
errIns_t insert_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, singleList_t<data_t> *newNode, unsigned pos = 0);






template <class data_t>
errDel_t delete_Head(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1);

template <class data_t>
errDel_t delete_Tail(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1);

template <class data_t>
errDel_t delete_Before(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0);

template <class data_t>
errDel_t delete_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0);

template <class data_t>
errDel_t delete_Node(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0);

template <class data_t>
errDel_t delete_All(singleList_t<data_t> *&head, singleList_t<data_t> *&tail);



/*** Overide above functions***/


// template <class data_t>
// void traverse_List(singleList_t<data_t> *head, data_t data, void(*subTask)(data_t &data_, data_t data));




// template <class data_t>
// singleList_t<data_t> *get_Node(singleList_t<data_t> *head, unsigned pos = 0);




// template <class data_t>
// singleList_t<data_t> *add_Before(singleList_t<data_t> *&head, unsigned num = 1, unsigned pos = 0, addMode_t addMode = QUEUE);

// template <class data_t>
// singleList_t<data_t> *add_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0);




// template <class data_t>
// errDel_t delete_Before(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1);

// template <class data_t>
// errDel_t delete_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1);









/* -----------------------------------------------------------------------------
/* Extern functions template definition
/*
/* -------------------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> singleList_t<data_t> *create_List(singleList_t<data_t> *&head, unsigned num)
 * \brief               Create a brand new list having num nodes
 * \param   head        Head of empty single list
 * \param   num         Number of nodes will be added
 * \return              Pointer to tail of single list
**/
template <class data_t>
singleList_t<data_t> *create_List(singleList_t<data_t> *&head, unsigned num = 1)
{
    if(num > 0)
    {
        singleList_t<data_t> *singleList_tail = head;

        for(int i = 1; i <= num; ++i)
        {
            singleList_t<data_t> *node_new = new singleList_t<data_t>();
            node_new->set_next(nullptr);

            if(i == 1)
            {
                head            = node_new;
                singleList_tail = node_new;
            }

            else
            {
                singleList_tail->set_next(node_new);
                singleList_tail = node_new;
            }
        }

        return singleList_tail;
    }

    else
    {
        return nullptr;
    }
}


/**
 * \fn                  template <class data_t> void traverse_List(singleList_t<data_t> *head, void (*subTask)(data_t data))
 * \brief               Traverse through the nodes and do subTask att every node
 * \param   head        Head of single list
 * \param   subTask     Pointer to a function doing something with argument is data_ of each node in list  
 * \return              Pointer to tail of single list
**/
template <class data_t>
void traverse_List(singleList_t<data_t> *head, void (*subTask)(data_t &data_))
{
    if(true)
    {
        singleList_t<data_t> *node_curr = head;
        while(node_curr != nullptr)
        {
            (*subTask)(node_curr->data_);
            node_curr = node_curr->get_next();
        }
    }
}


/**
 * \fn                  void arrange_List(singleList_t<data_t> *head, void (*conTask)(data_t data1_, data_t data2_))
 * \brief               Arrange single list base on condition task
 * \param   head        Head of single list
 * \param   conTask     Condition for swapping data of two node
 * \return              void
**/
template <class data_t>
void arrange_List(singleList_t<data_t> *head, bool (*conTask)(data_t data1_, data_t data2_))
{
    #if true

        data_t data_temp;

        for(singleList_t<data_t> *node_1 = head; node_1 != nullptr; node_1 = node_1->get_next())
        {
            for(singleList_t<data_t> *node_2 = node_1; node_2 != nullptr; node_2 = node_2->get_next())
            {
                if((*conTask)(node_1->data_, node_2->data_))
                {
                    data_temp     = node_1->data_;
                    node_1->data_ = node_2->data_;
                    node_2->data_ = data_temp;
                }
            }
        }

    #endif
}


/**
 * \fn                  template <class data_t> singleList_t<data_t> *get_Tail(singleList_t<data_t> *head)
 * \brief               Get pointer to tail of single list
 * \param   head        Head of single list
 * \return              Pointer to tail of single list
**/
template <class data_t>
singleList_t<data_t> *get_Tail(singleList_t<data_t> *head)
{
    #if true

        if(head == nullptr) {return nullptr;}

        singleList_t<data_t> *tail = head;

        while(tail->get_next() != nullptr)
        {
            tail = tail->get_next();
        }

        return tail;
    
    #endif
}


/**
 * \fn                  template <class data_t> int get_Index(singleList_t<data_t> *head, bool (*conTask)(data_t data_))
 * \brief               Get index of node passed
 * \param   head        Head of single list
 * \param   conTask     Condition for find expected node
 * \return              Index of node
**/
template <class data_t>
int get_Index(singleList_t<data_t> *head, bool (*conTask)(data_t data_))
{
    #if true

        if(head == nullptr) {return -1;}

        singleList_t<data_t> *node_curr = head;

        int i = 0;
        while(node_curr != nullptr)
        {
            if((*conTask)(node_curr->data_)){return i;}

            ++i;
            node_curr = node_curr->get_next();
        }

        return -1;
    
    #endif
}



/**
 * \fn                  template <class data_t> singleList_t<data_t> *get_Node(singleList_t<data_t> *head, unsigned pos = 0)
 * \brief               Get pointer to tail of single list
 * \param   head        Head of single list
 * \param   pos         Position of node wanted to get
 * \return              Pointer to node wanted to get
**/
template <class data_t>
singleList_t<data_t> *get_Node(singleList_t<data_t> *head, unsigned pos = 0)
{
    if(true)
    {
        singleList_t<data_t> *node_curr = head;

        int i = 0;
        while(i < pos && node_curr->get_next() != nullptr)
        {
            node_curr = node_curr->get_next();
            ++i;
        }

        // pos > number of
        if(node_curr->get_next() == nullptr && i < pos)
        {
            return nullptr;
        }

        return node_curr;
    }
}



/**
 * \fn                  singleList_t<data_t> *find_Node(singleList_t<data_t> *head, bool(*conTask)(data_t data_), unsigned from = 0)
 * \brief               Find node which is suit with conition task from specific position
 * \param   head        Head of single list
 * \param   conTask     Condition task
 * \param   from        Finding start from this position
 * \return              First pointer to node wanted to find
**/
template <class data_t>
singleList_t<data_t> *find_Node(singleList_t<data_t> *head, bool(*conTask)(data_t data_), unsigned from = 0)
{
    #if true

        singleList_t<data_t> *node_curr = get_Node(head, from);

        bool cond = (*conTask)(node_curr->data_);
        
        while(!cond && node_curr->get_next() != nullptr)
        {
            node_curr = node_curr->get_next();
            cond = (*conTask)(node_curr->data_);
        }

        if(cond) {return node_curr;}

        return nullptr;

    #endif
}



/**
 * \fn                  template <class data_t> singleList_t<data_t> *add_Head(singleList_t<data_t> *&head, unsigned num, addMode_t addMode)
 * \brief               Add new nodes at head of single list
 * \param   head        Head of single list
 * \param   num         Number of nodes will be added
 * \param   addMode     How to add new nodes: STACK or QUEUE
 * \return              Pointer to head of single list after inserting
**/
template <class data_t>
singleList_t<data_t> *add_Head(singleList_t<data_t> *&head, unsigned num = 1, addMode_t addMode = QUEUE)
{
    if(head != nullptr && num > 0)
    {
        if(addMode == QUEUE)
        {
            singleList_t<data_t> *singleList_head = nullptr;
            singleList_t<data_t> *singleList_tail = create_List(singleList_head, num);

            singleList_tail->set_next(head);
            head = singleList_head;
        }

        else if(addMode == STACK)
        {
            for(int i = 1; i <= num; ++i)
            {
                singleList_t<data_t> *node_new = new singleList_t<data_t>();

                node_new->set_next(head);

                head = node_new;
            }
        }

        return head;
    }

    else
    {
        return nullptr;
    }
}


/**
 * \fn                  template <class data_t> \singleList_t<data_t> *add_Tail(singleList_t<data_t> *&tail)
 * \brief               Add new nodes at tail of single list
 * \param   tail        Tail of single list
 * \param   num         Number of nodes will be added
 * \return              Pointer to tail of single list after inserting
**/
template <class data_t>
singleList_t<data_t> *add_Tail(singleList_t<data_t> *&tail, unsigned num = 1)
{
    if(tail != nullptr && num > 0)
    {
        for(int i = 1; i <= num; ++i)
        {
            singleList_t<data_t> *node_new = new singleList_t<data_t>();

            tail->set_next(node_new);

            tail = node_new;
        }

        return tail;
    }

    else
    {
        return nullptr;
    }
}


/**
 * \fn                  template <class data_t> singleList_t<data_t> *add_Before(singleList_t<data_t> *&head, unsigned num, unsigned pos)
 * \brief               Add new nodes before a specified position
 * \param   head        Head of single list
 * \param   num         Number of nodes will be added
 * \param   pos         Position for add nodes
 * \param   addMode     How to add new nodes: STACK or QUEUE
 * \return              Pointer to final node added
**/
template <class data_t>
singleList_t<data_t> *add_Before(singleList_t<data_t> *&head, unsigned num = 1, unsigned pos = 0, addMode_t addMode = QUEUE)
{
    if(true)
    {
        if(head != nullptr && num > 0)
        {
            if(pos == 0)
            {
                return add_Head(head, num, addMode);
            }

            else
            {
                singleList_t<data_t> *node_curr = head;
                singleList_t<data_t> *node_befo = head;

                int i = 0;
                while(i < pos && node_curr->get_next() != nullptr)
                {
                    node_befo = node_curr;
                    node_curr = node_curr->get_next();
                    ++i;
                }

                // pos > number of nodes
                if(node_curr->get_next() == nullptr && i < pos)
                {
                    return nullptr;
                }

                singleList_t<data_t> *temp = add_Head(node_curr, num, addMode);
                node_befo->set_next(temp);

                return temp;
            }
        }

        else
        {
            return nullptr;
        }
    }
}


/**
 * \fn                  template <class data_t> singleList_t<data_t> *add_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail unsigned num, unsigned pos)
 * \brief               Add new nodes after a specified position
 * \param   head        Head of single list
 * \param   tail        Tail of single list
 * \param   num         Number of nodes will be added
 * \param   pos         Position for add nodes
 * \return              Pointer to final node added
**/
template <class data_t>
singleList_t<data_t> *add_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
{
#if true
    if(head != nullptr && tail != nullptr && num > 0)
    {
        if(pos == 0)
        {
            if(head == tail)
            {
                return add_Tail(tail, num);
            }

            else
            {
                singleList_t<data_t> *singleList_head = nullptr;
                singleList_t<data_t> *singleList_tail = create_List(singleList_head, num);

                // sub-list tail is linked to 1th node of old list
                singleList_tail->set_next(head->get_next());

                // First node of old list is linked to sub-list head
                head->set_next(singleList_head);

                return singleList_tail;

            }
        }

        // pos > 0
        else
        {
            singleList_t<data_t> *node_curr = head;

            int i = 0;
            while(i < pos && node_curr->get_next() != nullptr)
            {
                node_curr = node_curr->get_next();
                ++i;
            }

            if(node_curr->get_next() == nullptr)
            {
                // pos is tail of single list
                if(i == pos)
                {
                    return add_Tail(tail, num);
                }

                // pos > number of nodes
                else
                {
                    return nullptr;
                }
            }

            else
            {
                singleList_t<data_t> *node_next = node_curr->get_next();

                singleList_t<data_t> *temp = add_Tail(node_curr, num);

                temp->set_next(node_next);

                return temp;
            }
        }
    }

    else
    {
        return nullptr;
    }
#endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_Head(singleList_t<data_t> *&head, singleList_t<data_t> *newNode)
 * \brief               Insert an existing node before the head of list
 * \param   head        Head of single list
 * \param   newNode     Node is inserted
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_Head(singleList_t<data_t> *&head, singleList_t<data_t> *newNode)
{
    #if true

        if(head    == nullptr)  {return E_INS_HEAD;     }
        if(newNode == nullptr)  {return E_INS_NEW_NODE; }

        singleList_t<data_t> *node_new = new singleList_t<data_t>();
        node_new = newNode;

        node_new->set_next(head);
        head = node_new;

        return E_INS_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_Tail(singleList_t<data_t> *&tail, singleList_t<data_t> *newNode)
 * \brief               Insert an existing node after the tail of list
 * \param   tail        Tail of single list
 * \param   newNode     Node is inserted
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_Tail(singleList_t<data_t> *&tail, singleList_t<data_t> *newNode)
{
    #if true

        if(tail    == nullptr)  {return E_INS_TAIL;     }
        if(newNode == nullptr)  {return E_INS_NEW_NODE; }

        singleList_t<data_t> *node_new = new singleList_t<data_t>();
        node_new = newNode;

        node_new->set_next(nullptr);
        tail    ->set_next(newNode);
        tail    = node_new;

        return E_INS_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_Before(singleList_t<data_t> *&head, singleList_t<data_t> *newNode, unsigned pos = 0)
 * \brief               Insert an existing node before specific node in the list
 * \param   head        Head of single list
 * \param   newNode     Node is inserted
 * \param   pos         newNode is inserted before this position
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_Before(singleList_t<data_t> *&head, singleList_t<data_t> *newNode, unsigned pos = 0)
{
    #if true

        if(head    == nullptr)  {return E_INS_HEAD;     }
        if(newNode == nullptr)  {return E_INS_NEW_NODE; }

        // pos = head
        if(pos == 0) {return insert_Head(head, newNode);}


        /*** pos > head ***/


        singleList_t<data_t> *node_curr = head;
        singleList_t<data_t> *node_befo = head;

        int i = 0;
        while(i < pos && node_curr->get_next() != nullptr)
        {
            node_befo = node_curr;
            node_curr = node_curr->get_next();
            ++i;
        }

        // pos > number of nodes
        if(node_curr->get_next() == nullptr && i < pos)
        {
            return E_INS_POS;
        }

        singleList_t<data_t> *node_new = new singleList_t<data_t>();
        node_new = newNode;

        node_befo->set_next(node_new);
        node_new->set_next(node_curr);

        return E_INS_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, singleList_t<data_t> *newNode, unsigned pos = 0)
 * \brief               Insert an existing node after specific node in the list
 * \param   head        Head of single list
 * \param   tail        Tail of single list
 * \param   newNode     Node is inserted
 * \param   pos         newNode is inserted after this position
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, singleList_t<data_t> *newNode, unsigned pos = 0)
{
    #if true

        if(head    == nullptr)  {return E_INS_HEAD;     }
        if(tail    == nullptr)  {return E_INS_TAIL;     }
        if(newNode == nullptr)  {return E_INS_NEW_NODE; }

        // There is 1 node
        if(head == tail) {return insert_Tail(tail, newNode);}



        /*** There are many nodes ***/


        singleList_t<data_t> *node_curr = head;

        int i = 0;
        while(i < pos && node_curr->get_next() != nullptr)
        {
            node_curr = node_curr->get_next();
            ++i;
        }

        // pos > number of nodes
        if(node_curr->get_next() == nullptr && i < pos)
        {
            // pos is tail of single list
            if(i == pos){return insert_Tail(tail, newNode);}

            // pos > number of nodes
            if(i < pos){return E_INS_POS;}
            
        }

        // pos < number of nodes
        else
        {
            // node_curr -> node_next
            singleList_t<data_t> *node_next = node_curr->get_next();

            //        node_new
            // node_curr -> node_next
            singleList_t<data_t> *node_new = new singleList_t<data_t>();
            node_new = newNode;

            // node_curr -> node new -> node_next
            node_curr->set_next(node_new);
            node_new ->set_next(node_next);

        }

        return E_INS_OK;

    #endif
}




/**
 * \fn                  template <class data_t> errDel_t delete_Head(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1)
 * \brief               Delete first node n times
 * \param   head        Head of single list
 * \param   tail        Tail of single list
 * \param   num         Number of times that first node is deleted
 * \return              Error when using delete functions
**/
template <class data_t>
errDel_t delete_Head(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1)
{
#if true

    if(num  == 0)       {return E_DEL_NUM;  }
    if(head == nullptr) {return E_INS_HEAD; }
    if(tail == nullptr) {return E_INS_TAIL; }
    
    // There is 1 node
    if(head == tail)
    {
        singleList_t<data_t> *node_curr = head;
        delete node_curr;

        head = tail = nullptr;

        if(num != 1) {return W_DEL_NUM; }
    }

    else
    {
        singleList_t<data_t> *node_befo = head;
        singleList_t<data_t> *node_curr = head;

        int i = 0;
        while(node_curr != nullptr && i < num)
        {
            node_befo = node_curr;
            node_curr = node_curr->get_next();
            delete node_befo;
            ++i;
        }
                    
        head = node_curr;

        // Now list is empty
        if(node_curr == nullptr)
        {
            tail = nullptr;
            if(i < num -1) {return W_DEL_NUM;}
        }
    }

    return E_INS_OK;
            
#endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_Tail(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1)
 * \brief               Delete last node n times
 * \param   head        Head of single list
 * \param   tail        Tail of single list
 * \param   num         Number of times that last node is deleted
 * \return              void
**/
template <class data_t>
errDel_t delete_Tail(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1)
{
    #if true

        if(num  == 0)       {return E_DEL_NUM;  }
        if(head == nullptr) {return E_INS_HEAD; }
        if(tail == nullptr) {return E_INS_TAIL; }
        
        if(num == 1)
        {
            // There is 1 node
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
            }

            else
            {
                singleList_t<data_t> *node_befo = head;
                singleList_t<data_t> *node_curr = head;

                while(node_curr->get_next() != nullptr)
                {
                    node_befo = node_curr;
                    node_curr = node_curr->get_next();
                }
                        
                node_befo->set_next(nullptr);
                tail = node_befo;
                delete node_curr;
            }
        }

        // Num > 1
        else
        {
            // There is 1 node
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;

                if(num != 1) {return W_DEL_NUM;}
            }

            else
            {
                // Delete n times
                for(int i = 0; i < num; ++i)
                {
                    // List is empty before completing deleting n nodes
                    if(delete_Tail(head, tail, 1) != E_INS_OK) {return W_DEL_NUM;}
                }
            }
        }

    return E_INS_OK;
                
#endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_Before(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
 * \brief               Delete <num> nodes before <pos>th node
 * \param   head        Head of single list
 * \param   tail        Tail of single list
 * \param   num         Number of nodes will be deleted
 * \param   pos         Position for deleting nodes
 * \return              void
**/
template <class data_t>
errDel_t delete_Before(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
{
    #if true

        if(num  == 0)       {return E_DEL_NUM;  }
        if(head == nullptr) {return E_INS_HEAD; }
        if(tail == nullptr) {return E_INS_TAIL; }



        return E_INS_OK;
        
    #endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
 * \brief               Delete <num> nodes after <pos>th node
 * \param   head        Head of single list
 * \param   tail        Tail of single list
 * \param   num         Number of nodes will be deleted
 * \param   pos         Position for deleting nodes
 * \return              void
**/
template <class data_t>
errDel_t delete_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
{
    #if true

        if(num  == 0)       {return E_DEL_NUM;  }
        if(head == nullptr) {return E_INS_HEAD; }
        if(tail == nullptr) {return E_INS_TAIL; }



        return E_INS_OK;
        
    #endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_Node(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
 * \brief               Delete <pos>th node <num>th times
 * \param   head        Head of single list
 * \param   tail        Tail of single list
 * \param   num         Number of times deleting node
 * \param   pos         Position of node
 * \return              void
**/
template <class data_t>
errDel_t delete_Node(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
{
    #if true

        if(num  == 0)       {return E_DEL_NUM;  }
        if(head == nullptr) {return E_INS_HEAD; }
        if(tail == nullptr) {return E_INS_TAIL; }

        if(num == 1)
        {
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
            }

            else if(pos == 0)
            {
                singleList_t<data_t> *node_befo = head;
                singleList_t<data_t> *node_curr = head;

                node_befo = node_curr;
                node_curr = node_curr->get_next();
                delete node_befo;

                head = node_curr; 
            }

            else 
            {
                singleList_t<data_t> *node_befo = head;
                singleList_t<data_t> *node_curr = head;

                int i = 0;
                while(node_curr->get_next() != nullptr && i < pos)
                {
                    node_befo = node_curr;
                    node_curr = node_curr->get_next();
                    ++i;
                }

                if(node_curr->get_next() == nullptr)
                {
                    if(i < pos) {return E_INS_POS;}

                    else if(i == pos)
                    {
                        node_befo->set_next(nullptr);
                        tail = node_befo;
                        delete node_curr;
                    }
                }

                else
                {
                    node_befo->set_next(node_curr->get_next());
                    delete node_curr;                        
                }
            }
        }

        // Num > 1
        else
        {
            // There is 1 node
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;

                if(num > 1) {return W_DEL_NUM;}
            }

            else
            {
                // Delete 1 node n times
                for(int i = 0; i < num; ++i)
                {
                    errDel_t ret = delete_Node(head, tail, 1, pos);
                    if(ret != E_INS_OK) {return ret;}
                }
            }
        }
                
        return E_INS_OK;
                
    #endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_All(singleList_t<data_t> *&head, singleList_t<data_t> *&tail)
 * \brief               Delete all nodes of list
 * \param   head        Head of single list
 * \param   tail        Tail of single list
 * \return              void
**/
template <class data_t>
errDel_t delete_All(singleList_t<data_t> *&head, singleList_t<data_t> *&tail)
{
    #if true

        if(head == nullptr) {return E_INS_HEAD; }
        if(tail == nullptr) {return E_INS_TAIL; }

        singleList_t<data_t> *node_curr = head;

        // There are many nodes
        while(head->get_next() != nullptr)
        {
            node_curr = head;
            head = head->get_next();
            delete node_curr;
        }

        // There is one node
        delete head;
        head = tail = nullptr;

        return E_INS_OK;

#endif
}




/*** Overide ***/








/* -----------------------------------------------------------------------------
/* Member functions of class template
/*
/* -------------------------------------------------------------------------- */

/**
 * \fn                  template <class data_t> singleList_t<data_t>::singleList_t<data_t>()
 * \brief               Initialize data_ is set by hand, pointer to next node is nullptr
 * \param               void
 * \return              void
**/
template <class data_t>
singleList_t<data_t>::singleList_t<data_t>()
{
    if(true)
    {
        this->ptr_next_ = nullptr;
    }
}

/**
 * \fn                  template <class data_t> void singleList_t<data_t>::set_next()
 * \brief               Set pointer to next node
 * \param   ptr_next    Pointer to next node
 * \return              void
**/
template <class data_t>
void singleList_t<data_t>::set_next(singleList_t<data_t> *ptr_next)
{
    if(true)
    {
        this->ptr_next_ = ptr_next;
    }
}


/**
 * \fn                  template <class data_t> singleList_t<data_t> *singleList_t<data_t>::get_next()
 * \brief               Get pointer to next node
 * \param               void
 * \return              Pointer to the next node
**/
template <class data_t>
singleList_t<data_t> *singleList_t<data_t>::get_next()
{
    if(true)
    {
        return ptr_next_;
    }
}

#endif // SINGLE_LIST_H
