/*
 * publisher_list.h
 *
 *  Created on: 15/ago/2010
 *      Author: mosca
 */

#ifndef PUBLISHER_LIST_H_
#define PUBLISHER_LIST_H_

#include "subscriber_list.h"
#include "ps_type.h"


#define MAX_PUBLISHER_NAME_LENGHT 15

typedef char publisher_name[MAX_PUBLISHER_NAME_LENGHT];

struct publisher {
    publisher_name name;
    subscribers_p subscribers;
    struct publisher* next;
    struct publisher* prev;
};

typedef struct publisher publisher_t;
typedef publisher_t* publisher_p;

typedef struct publishers {
    publisher_p head;
    publisher_p pointer;
    publisher_p tail;
    int reverse;
} publishers_t;

typedef publishers_t* publishers_p;

#endif /* PUBLISHER_LIST_H_ */

/*
        publishers_list_new
        -----------------------------------------------------------------------------
        Parameters:
            [out] publishers_list : A pointer to a publishers list.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            The function generate the structure for control a publishers list.
*/
PSErrors publishers_list_new(publishers_p* publishers_list);

/*
        publisher_new
        -----------------------------------------------------------------------------
        Parameters:
            [out] publisher : A pointer to a publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            The function generate the structure for rappresent a publisher.
*/
PSErrors publisher_new(publisher_p *publisher);

/*
        publisher_init
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher : The publisher structure generated by publisher_new.
            [in]  name  : The name of a publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Inizialize the publisher structure and assign a name.
*/
PSErrors publisher_init(publisher_p publisher, publisher_name name);

/*
        publisher_tail_add
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
            [in]  publisher : A publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Add a publisher in tail of the list.
*/
PSErrors publisher_tail_add(publishers_p publisher_list, publisher_p publisher);

/*
        publisher_head_add
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
            [in]  publisher : A publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Add a publisher in head of the list.
*/
PSErrors publisher_head_add(publishers_p publisher_list, publisher_p publisher);

/*
        publisher_delete
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
            [in]  publisher : A publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Delete a publisher from the list
*/
PSErrors publisher_delete(publishers_p publisher_list, publisher_p publisher);

/*
        publishers_delete
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Delete all publishers from the list.
*/
PSErrors publishers_delete(publishers_p publisher_list);

/*
        publisher_next
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
            [in]  publisher : The current publisher.
            [out] next_publisher : The next publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Return the publisher after the current one.
*/
PSErrors publisher_next(publishers_p publisher_list, publisher_p publisher, publisher_p* next_publisher);

/*
        publisher_prev
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
            [in]  publisher : The current publisher.
            [out] prev_publisher : The previous publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Return the publisher before the current one.
*/
PSErrors publisher_prev(publishers_p publisher_list, publisher_p publisher, publisher_p* prev_publisher);

/*
        publisher_head
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
            [out]  publisher : The head publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Return the first publisher on the list.
*/
PSErrors publishers_head(publishers_p publisher_list, publisher_p *publisher);

/*
        publisher_tail
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
            [out]  publisher : The tail publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Return the last publisher on the list.
*/
PSErrors publishers_tail(publishers_p publisher_list, publisher_p *publisher);

/*
        publisher_next_on_publishers
        -----------------------------------------------------------------------------
        Parameters:
            [in]   publisher_list : The list of publishers.
            [out]  publisher : The next publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Return the next publisher after the one pointed from an internal publisher_list pointer.
*/
PSErrors publisher_next_on_publishers(publishers_p publisher_list, publisher_p* publisher);

/*
        publisher_is_reverse
        -----------------------------------------------------------------------------
        Parameters:
            [in]   publisher_list : The list of publishers.
        -----------------------------------------------------------------------------
        Returns:
            1 if the list is reversed 0 else
        -----------------------------------------------------------------------------
        Description:
            Check if the list is reversed or not.
*/
int publishers_is_reverse(publishers_p publisher_list);

/*
        publisher_is_reverse
        -----------------------------------------------------------------------------
        Parameters:
            [in]   publisher_list : The list of publishers.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Reverse the list.
*/
PSErrors publishers_reverse(publishers_p publisher_list);

/*
        publisher_by_name_find
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
            [in]  name : The name of publisher.
            [out] publisher : The previous founded.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Find a publisher from his name, if the publisher pointer is NULL the function check only
            if the publisher exist and return StatusOK.
 */
PSErrors publishers_by_name_find(publishers_p publisher_list, publisher_name name, publisher_p *publisher);

/*
        publisher_by_name_delete
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
            [in]  name : The name of publisher.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Find a publisher from his name and delete it.
*/
PSErrors publisher_by_name_delete(publishers_p publisher_list, publisher_name name);

/*
        publisher_by_name_find
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The list of publishers.
            [in]  name : The name of publisher.
            [in]  subscriber : The subcriber.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Find a publisher from his name, and add a publisher to it.
*/
PSErrors publisher_by_name_add_subscriber(publishers_p publisher_list, publisher_name name, subscriber_p subscriber);

/*
        publisher_by_name_find
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher : The publisher.
            [in]  subscriber : The subcriber.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Add subscriber to the given publisher.
*/
PSErrors publisher_add_subscriber(publisher_p publisher, subscriber_p subscriber);

PSErrors publisher_reset_pointer(publishers_p publisher_list);

/*
        publisher_notify
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher : The publisher.
            [in]  data : The data structure.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Push data at all the subscribers added to publisher.
*/
PSErrors publisher_notify(publisher_p publisher, PSData_p data);

/*
        publisher_by_name_notify
        -----------------------------------------------------------------------------
        Parameters:
            [in]  publisher_list : The publisher.
            [in]  name : The name of publisher
            [in]  data : The data structure.
        -----------------------------------------------------------------------------
        Returns:
            An error code about the execution of the function.
        -----------------------------------------------------------------------------
        Description:
            Find a publisher by name and push data at all the subscribers added to it
*/
PSErrors publisher_by_name_notify(publishers_p publisher_list, publisher_name name, PSData_p);

//TO-DO

PSErrors publisher_add_and_create_subscriber(publisher_p,subscriber_name,update_fun,subscriber_p*);
PSErrors publisher_new_init_tail_add(publishers_p publisher_list,publisher_name,publisher_p*);
PSErrors publisher_notify_test(publisher_p);
/*
PSErrors publisher_notify_all(publishers_p publishers_list,PSData_p)
PSErrors publisher_notify_test_add_subscriber_name(publisher_p,PSData_p);
 */