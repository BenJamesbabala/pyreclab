#ifndef __PY_INTERFACE_H__
#define __PY_INTERFACE_H__

#include "DataReader.h"
#include "RatingMatrix.h"
#include "RecSysAlgorithm.h"
#include "MAE.h"
#include "RMSE.h"

#include <Python.h>


typedef struct
{
   PyObject_HEAD
   DataReader* m_trainingReader;
   RatingMatrix* m_ratingMatrix;
   RecSysAlgorithm* m_recAlgorithm;
   MAE m_mae;
   RMSE m_rmse;
} Recommender;

void Recommender_dealloc( Recommender* self );
PyObject* Recommender_train( Recommender* self, PyObject* args, PyObject* kwds );
PyObject* Recommender_test( Recommender* self, PyObject* args, PyObject* kwdict );
PyObject* Recommender_predict( Recommender* self, PyObject* args, PyObject* kwds );

#endif // __PY_INTERFACE_H__

