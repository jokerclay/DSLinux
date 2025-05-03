#ifndef _QUEUE_H
#define _QUEUE_H

// sqQueue
//               |
//               v
// front-> 1 2 3 4 -> rear
//         |
//         v
//

#define sqQueueMaxSize 5
#define sqQueueElementType int
typedef struct {
    sqQueueElementType data[sqQueueMaxSize];
    int front,rear;
}sqQueue;

void sqQueueInitQueue (sqQueue &Q);
bool sqQueueQueueEmpty(sqQueue Q);
bool sqQueueEnQueue(sqQueue &Q,sqQueueElementType e);
bool sqQueueDeQueue   (sqQueue &Q,sqQueueElementType &e);
bool sqQueueGetHead   (sqQueue Q ,sqQueueElementType  &e);

#endif // _QUEUE_H
