% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/model.R
\name{fit.h2o4gpu_model}
\alias{fit.h2o4gpu_model}
\title{Train an H2O4GPU Estimator}
\usage{
\method{fit}{h2o4gpu_model}(object, x, y = NULL, ...)
}
\arguments{
\item{object}{The h2o4gpu model object}

\item{x}{The training data where each column represents a different predictor variable
to be used in building the model.}

\item{y}{A vector of numeric values to be used as response variable in building the model.
Note that if the vector is character or factor, it will be converted to numeric column
(e.g. 0, 1, 2, ...) implicitly. For unsupervised models, this argument can be ignored or
specified as \code{NULL}.}

\item{...}{Additional arguments (unused for now).}
}
\description{
This function builds the model using the training data specified.
}
