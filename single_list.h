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
 *      Singly list, doubly list, circular list:
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

// Callback function: Initialize data of node
// typedef void (*dataInit_t)();

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
    E_NUM   = 0,

    // Function is ok
    E_OK    = 1,

    // Head of list is nullptr
    E_HEAD  = 2,

    // Tail of list is nullptr
    E_TAIL  = 3,

    // Position > number of nodes
    E_POS   = 4,

    // All nodes are deleted, but num input > number of nodes
    W_NUM   = 5,

} errDel_t;









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

    // Type definition
public:
    typedef void (*dataInit_t)(data_t data);


    // Variables
private:
    singleList_t *ptr_next_;

public:
    data_t  data;


    // Get functions
public:
    singleList_t *get_next();


    // Set functions
public:
    void set_next(singleList_t *ptr_next);


    // Function protocols
public:

    singleList_t();


    /*** Delete node ***/
    void delete_First();
    void delete_Last();
    errDel_t delete_All();

    errDel_t delete_Node();
    errDel_t delete_Before();
    errDel_t delete_After();

};









/* -----------------------------------------------------------------------------
/* Extern functions template protocols
/*
/* -------------------------------------------------------------------------- */

template <class data_t>
singleList_t<data_t> *create_List(singleList_t<data_t> *&head, unsigned num = 1);

template <class data_t>
void traverse_List(singleList_t<data_t> *head, void (*subTask)(data_t data));



template <class data_t>
singleList_t<data_t> *get_Tail(singleList_t<data_t> *head);

template <class data_t>
singleList_t<data_t> *get_Node(singleList_t<data_t> *head, unsigned pos = 0);




template <class data_t>
singleList_t<data_t> *add_Head(singleList_t<data_t> *&head, unsigned num = 1, addMode_t addMode = QUEUE);

template <class data_t>
singleList_t<data_t> *add_Tail(singleList_t<data_t> *&tail, unsigned num = 1);

template <class data_t>
singleList_t<data_t> *add_Before(singleList_t<data_t> *&head, unsigned num = 1, unsigned pos = 0, addMode_t addMode = QUEUE);

template <class data_t>
singleList_t<data_t> *add_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0);




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
// void traverse_List(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, void(*subTask)());




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
 * \param   head        Head of empty singly list
 * \param   num         Number of nodes will be added
 * \return              Pointer to tail of singly list
**/
template <class data_t>
singleList_t<data_t> *create_List(singleList_t<data_t> *&head, unsigned num = 1)
{
    if(num > 0)
    {
        singleList_t<data_t> *singlyList_tail = head;

        for(int i = 1; i <= num; ++i)
        {
            singleList_t<data_t> *singlyList_new = new singleList_t<data_t>();
            singlyList_new->set_next(nullptr);

            if(i == 1)
            {
                head            = singlyList_new;
                singlyList_tail = singlyList_new;
            }

            else
            {
                singlyList_tail->set_next(singlyList_new);
                singlyList_tail = singlyList_new;
            }
        }

        return singlyList_tail;
    }

    else
    {
        return nullptr;
    }
}


/**
 * \fn                  template <class data_t> void traverse_List(singleList_t<data_t> *head, void (*subTask)(data_t data))
 * \brief               Traverse through the nodes and do subTask att every node
 * \param   head        Head of singly list
 * \param   subTask     Pointer to a function having argument is data of node   
 * \return              Pointer to tail of singly list
**/
template <class data_t>
void traverse_List(singleList_t<data_t> *head, void (*subTask)(data_t data))
{
    if(true)
    {
        singleList_t<data_t> *node_curr = head;
        while(node_curr != nullptr)
        {
            (*subTask)(node_curr->data);
            node_curr = node_curr->get_next();
        }
    }
}


/**
 * \fn                  template <class data_t> singleList_t<data_t> *get_Tail(singleList_t<data_t> *head)
 * \brief               Get pointer to tail of singly list
 * \param   head        Head of singly list
 * \return              Pointer to tail of singly list
**/
template <class data_t>
singleList_t<data_t> *get_Tail(singleList_t<data_t> *head)
{
    if(true)
    {
        singleList_t<data_t> *tail = head;

        while(tail->get_next() != nullptr)
        {
            tail = tail->get_next();
        }

        return tail;
    }
}



/**
 * \fn                  template <class data_t> singleList_t<data_t> *get_Node(singleList_t<data_t> *head, unsigned pos = 0)
 * \brief               Get pointer to tail of singly list
 * \param   head        Head of singly list
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
 * \fn                  template <class data_t> singleList_t<data_t> *add_Head(singleList_t<data_t> *&head, unsigned num, addMode_t addMode)
 * \brief               Add new nodes at head of singly list
 * \param   head        Head of singly list
 * \param   num         Number of nodes will be added
 * \param   addMode     How to add new nodes: STACK or QUEUE
 * \return              Pointer to head of singly list after inserting
**/
template <class data_t>
singleList_t<data_t> *add_Head(singleList_t<data_t> *&head, unsigned num = 1, addMode_t addMode = QUEUE)
{
    if(head != nullptr && num > 0)
    {
        if(addMode == QUEUE)
        {
            singleList_t<data_t> *singlyList_head;
            singleList_t<data_t> *singlyList_tail = create_List(singlyList_head, num);

            singlyList_tail->set_next(head);
            head = singlyList_head;
        }

        else if(addMode == STACK)
        {
            for(int i = 1; i <= num; ++i)
            {
                singleList_t<data_t> *singlyList_new = new singleList_t<data_t>();

                singlyList_new->set_next(head);

                head = singlyList_new;
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
 * \brief               Add new nodes at tail of singly list
 * \param   tail        Tail of singly list
 * \param   num         Number of nodes will be added
 * \return              Pointer to tail of singly list after inserting
**/
template <class data_t>
singleList_t<data_t> *add_Tail(singleList_t<data_t> *&tail, unsigned num = 1)
{
    if(tail != nullptr && num > 0)
    {
        for(int i = 1; i <= num; ++i)
        {
            singleList_t<data_t> *singlyList_new = new singleList_t<data_t>();

            tail->set_next(singlyList_new);

            tail = singlyList_new;
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
 * \param   head        Head of singly list
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
 * \param   head        Head of singly list
 * \param   tail        Tail of singly list
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
                singleList_t<data_t> *singlyList_head = nullptr;
                singleList_t<data_t> *singlyList_tail = create_List(singlyList_head, num);

                // sub-list tail is linked to 1th node of old list
                singlyList_tail->set_next(head->get_next());

                // First node of old list is linked to sub-list head
                head->set_next(singlyList_head);

                return singlyList_tail;

            }
        }

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
                // pos is tail of singly list
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
                singleList_t<data_t> *singlyList_next = node_curr->get_next();

                singleList_t<data_t> *temp = add_Tail(node_curr, num);

                temp->set_next(singlyList_next);

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
 * \fn                  template <class data_t> errDel_t delete_Head(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1)
 * \brief               Delete first node n times
 * \param   head        Head of singly list
 * \param   tail        Tail of singly list
 * \param   num         Number of times that first node is deleted
 * \return              void
**/
template <class data_t>
errDel_t delete_Head(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1)
{
#if true
    if(num > 0)
    {
        if(head != nullptr)
        {
            if(tail != nullptr)
            {
                // There is 1 node
                if(head == tail)
                {
                    delete head;
                    head = tail = nullptr;

                    if(num != 1) {return W_NUM; }
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
                        if(i < num -1) {return W_NUM;}
                    }
                }

                return E_OK;
            }

            return E_TAIL;
        }

        return E_HEAD;
    }

    return E_NUM;
#endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_Tail(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1)
 * \brief               Delete last node n times
 * \param   head        Head of singly list
 * \param   tail        Tail of singly list
 * \param   num         Number of times that last node is deleted
 * \return              void
**/
template <class data_t>
errDel_t delete_Tail(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1)
{
#if true
    if(num > 0)
    {
        if(head != nullptr)
        {
            if(tail != nullptr)
            {
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

                        if(num != 1) {return W_NUM;}
                    }

                    else
                    {
                        // Delete n times
                        for(int i = 0; i < num; ++i)
                        {
                            // List is empty before completing deleting n nodes
                            if(delete_Tail(head, tail, 1) != E_OK) {return W_NUM;}
                        }
                    }
                }

                return E_OK;
            }

            return E_TAIL;
        }

        return E_HEAD;
    }

    return E_NUM;
#endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_Before(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
 * \brief               Delete <num> nodes before <pos>th node
 * \param   head        Head of singly list
 * \param   tail        Tail of singly list
 * \param   num         Number of nodes will be deleted
 * \param   pos         Position for deleting nodes
 * \return              void
**/
template <class data_t>
errDel_t delete_Before(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
{
#if true
    if(num > 0)
    {
        if(head != nullptr)
        {
            if(tail != nullptr)
            {
                
                return E_OK;
            }

            return E_TAIL;
        }

        return E_HEAD;
    }

    return E_NUM;
#endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
 * \brief               Delete <num> nodes after <pos>th node
 * \param   head        Head of singly list
 * \param   tail        Tail of singly list
 * \param   num         Number of nodes will be deleted
 * \param   pos         Position for deleting nodes
 * \return              void
**/
template <class data_t>
errDel_t delete_After(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
{
#if true
    if(num > 0)
    {
        if(head != nullptr)
        {
            if(tail != nullptr)
            {

                
                return E_OK;
            }

            return E_TAIL;
        }

        return E_HEAD;
    }

    return E_NUM;
#endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_Node(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
 * \brief               Delete <pos>th node <num>th times
 * \param   head        Head of singly list
 * \param   tail        Tail of singly list
 * \param   num         Number of times deleting node
 * \param   pos         Position of node
 * \return              void
**/
template <class data_t>
errDel_t delete_Node(singleList_t<data_t> *&head, singleList_t<data_t> *&tail, unsigned num = 1, unsigned pos = 0)
{
#if true
    if(num > 0)
    {
        if(head != nullptr)
        {
            if(tail != nullptr)
            {
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
                            if(i < pos) {return E_POS;}

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

                        if(num > 1) {return W_NUM;}
                    }

                    else
                    {
                        // Delete 1 node n times
                        for(int i = 0; i < num; ++i)
                        {
                            errDel_t ret = delete_Node(head, tail, 1, pos);
                            if(ret != E_OK) {return ret;}
                        }
                    }
                }
                
                return E_OK;
            }

            return E_TAIL;
        }

        return E_HEAD;
    }

    return E_NUM;
#endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_All(singleList_t<data_t> *&head, singleList_t<data_t> *&tail)
 * \brief               Delete all nodes of list
 * \param   head        Head of singly list
 * \param   tail        Tail of singly list
 * \return              void
**/
template <class data_t>
errDel_t delete_All(singleList_t<data_t> *&head, singleList_t<data_t> *&tail)
{
#if true
    if(head != nullptr)
    {
        if(tail != nullptr)
        {

            // There are many nodes
            while(head->get_next() != nullptr)
            {
                delete head;
                head = head->get_next();
            }

            // There is one node
            delete head;
            head = tail = nullptr;
                
            return E_OK;
        }

        return E_TAIL;
    }

    return E_HEAD;
#endif
}




/*** Overide ***/








/* -----------------------------------------------------------------------------
/* Member functions of class template
/*
/* -------------------------------------------------------------------------- */

/**
 * \fn                  template <class data_t> singleList_t<data_t>::singleList_t<data_t>()
 * \brief               Initialize pointer to next node is nullptr
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
