/*
 *  DecodeHintType.cpp
 *  zxing
 *
 *  Copyright 2010 ZXing authors All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <zxing/DecodeHints.h>
#include <zxing/common/IllegalArgumentException.h>
namespace zxing {

DecodeHints::DecodeHints() {
  hints = 0;
}

DecodeHints::DecodeHints(DecodeHintType init) {
  hints = init;
}

DecodeHints::~DecodeHints() {
  // if DecodeHintType requires a destructor in the future, call it here
}

void DecodeHints::addFormat(BarcodeFormat toadd) {
  switch (toadd) {
    case BarcodeFormat_QR_CODE: hints |= BARCODEFORMAT_QR_CODE_HINT; break;
    case BarcodeFormat_DATA_MATRIX: hints |= BARCODEFORMAT_DATA_MATRIX_HINT; break;
    case BarcodeFormat_UPC_E: hints |= BARCODEFORMAT_UPC_E_HINT; break;
    case BarcodeFormat_UPC_A: hints |= BARCODEFORMAT_UPC_A_HINT; break;
    case BarcodeFormat_EAN_8: hints |= BARCODEFORMAT_EAN_8_HINT; break;
    case BarcodeFormat_EAN_13: hints |= BARCODEFORMAT_EAN_13_HINT; break;
    case BarcodeFormat_CODE_128: hints |= BARCODEFORMAT_CODE_128_HINT; break;
    case BarcodeFormat_CODE_39: hints |= BARCODEFORMAT_CODE_39_HINT; break;
    case BarcodeFormat_ITF: hints |= BARCODEFORMAT_ITF_HINT; break;
    default: throw IllegalArgumentException("Unrecognizd barcode format");
  }
}

bool DecodeHints::containsFormat(BarcodeFormat tocheck) const {
  DecodeHintType checkAgainst;
  switch (tocheck) {
    case BarcodeFormat_QR_CODE: checkAgainst = BARCODEFORMAT_QR_CODE_HINT; break;
    case BarcodeFormat_DATA_MATRIX: checkAgainst = BARCODEFORMAT_DATA_MATRIX_HINT; break;
    case BarcodeFormat_UPC_E: checkAgainst = BARCODEFORMAT_UPC_E_HINT; break;
    case BarcodeFormat_UPC_A: checkAgainst = BARCODEFORMAT_UPC_A_HINT; break;
    case BarcodeFormat_EAN_8: checkAgainst = BARCODEFORMAT_EAN_8_HINT; break;
    case BarcodeFormat_EAN_13: checkAgainst = BARCODEFORMAT_EAN_13_HINT; break;
    case BarcodeFormat_CODE_128: checkAgainst = BARCODEFORMAT_CODE_128_HINT; break;
    case BarcodeFormat_CODE_39: checkAgainst = BARCODEFORMAT_CODE_39_HINT; break;
    case BarcodeFormat_ITF: checkAgainst = BARCODEFORMAT_ITF_HINT; break;
    default: throw IllegalArgumentException("Unrecognizd barcode format");
  }
  return (hints & checkAgainst);
}

void DecodeHints::setTryHarder(bool toset) {
  if (toset) {
    hints |= TRYHARDER_HINT;
  } else {
    hints &= ~TRYHARDER_HINT;
  }
}

bool DecodeHints::getTryHarder() const {
  return (hints & TRYHARDER_HINT);
}

} /* namespace */
