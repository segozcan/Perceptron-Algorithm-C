#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Flower {

    float x[4];
    int type; //1 rose, 0 tulip

} Flower;

Flower *getFlowers(int length, Flower *dataset) {

    int i = 0;
    for (i = 0; i < length; i++) {
        if (i == length - 1) {
            scanf(" %5f %5f %5f %5f %d", &dataset[i].x[0],
                    &dataset[i].x[1], &dataset[i].x[2],
                  &dataset[i].x[3], &dataset[i].type);
        } else {
            scanf(" %5f %5f %5f %5f %d\n", &dataset[i].x[0],
                    &dataset[i].x[1], &dataset[i].x[2],
                  &dataset[i].x[3], &dataset[i].type);
        }
    }
    return dataset;
}

float *updateWeigths(int epoch, float *weights, float rate,
                     Flower *dataset, int datasetLength) {

    int i = 0;
    int m = 0;
    int n = 0;
    float z;
    float a;

    for (n = 0; n < epoch; n++) {
        for (m = 0; m < datasetLength; m++) {

            z = weights[0] * dataset[m].x[0] + weights[1] * dataset[m].x[1]
                + weights[2] * dataset[m].x[2] + weights[3] * dataset[m].x[3];

            a = 1.0 / (1.0 + exp(-z));

            for (i = 0; i < 4; i++) {
                weights[i] += rate * (dataset[m].type - a) * a * (1.0 - a)
                              * dataset[m].x[i];
                printf("%f %d %d\n",weights[i],m,n);
            }
        }
    }

    return weights;
}

int main() {
/*
    float eben;
    scanf("%5f",&eben);
    printf("%f",eben);
    return 5;
*/
    int epoch;
    float rate;
    int datasetLength;
    Flower *dataset;
    float weights[4];
    float *result;

    scanf("%d\n", &epoch);
    scanf(" %5f\n", &rate);
    scanf("%5f %5f %5f %5f \n", weights, weights + 1, weights + 2, weights + 3);

    scanf(" %d\n", &datasetLength);

    dataset = (Flower *) malloc(datasetLength * sizeof(Flower));
    dataset = getFlowers(datasetLength, dataset);

    result = updateWeigths(epoch, weights, rate, dataset, datasetLength);

    printf("anan %.3f", result[3]);

    return 0;
}

