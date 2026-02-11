/*
 * buttondriver.h
 *
 *  Created on: Dec 20, 2025
 *      Author: Onur Fidan
 */

#ifndef MODULES_BUTTONDRIVER_H_
#define MODULES_BUTTONDRIVER_H_

void buttondriver_init();
int buttondriver_get_state();
void ButtonDriverIRQ_init();

#endif /* MODULES_BUTTONDRIVER_H_ */
