/* -*- c++ -*- */
/*
 * Copyright 2002,2007 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef _GRI_MMSE_FIR_INTERPOLATOR_CC_H_
#define _GRI_MMSE_FIR_INTERPOLATOR_CC_H_

#include <gr_complex.h>
#include <vector>

class gr_fir_ccf;

/*!
 * \brief Compute intermediate samples between signal samples x(k*Ts)
 * \ingroup filter_primitive
 *
 * This implements a Mininum Mean Squared Error interpolator with 8 taps.
 * It is suitable for signals where the bandwidth of interest B = 1/(4*Ts)
 * Where Ts is the time between samples.
 *
 * Although mu, the fractional delay, is specified as a float, it is actually
 * quantized.  0.0 <= mu <= 1.0.  That is, mu is quantized in the interpolate 
 * method to 32nd's of a sample.
 */

class gri_mmse_fir_interpolator_cc {
public:
  gri_mmse_fir_interpolator_cc ();
  ~gri_mmse_fir_interpolator_cc ();

  unsigned ntaps () const;
  unsigned nsteps () const;

  /*!
   * \brief compute a single interpolated output value.
   *
   * \p input must have ntaps() valid entries and be 8-byte aligned.
   * input[0] .. input[ntaps() - 1] are referenced to compute the output value.
   * \throws std::invalid_argument if input is not 8-byte aligned.
   *
   * \p mu must be in the range [0, 1] and specifies the fractional delay.
   *
   * \returns the interpolated input value.
   */
  gr_complex interpolate (const gr_complex input[], float mu);

protected:
  std::vector<gr_fir_ccf *>	filters;
};


#endif /* _GRI_MMSE_FIR_INTERPOLATOR_CC_H_ */
