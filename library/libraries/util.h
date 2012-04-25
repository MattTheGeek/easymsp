/*
 * util.h
 * Version: 1.0.0
 * Library for useful functions
 *
 * Author: Matthew Burmeister
 * Copyright Matthew Burmeister 2012. All Rights Reserved.
 *
 * Part of the EasyMSP Project.
 *
 */

/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma FUNC_IS_PURE (makeWordPinMask);
#pragma FUNCTION_OPTIONS (makeWordPinMask, "--opt_level=4 --opt_for_speed=5")
inline unsigned short int makeWordPinMask(unsigned short int pin)

#pragma FUNC_IS_PURE (makePinMask);
#pragma FUNCTION_OPTIONS (makePinMask, "--opt_level=4 --opt_for_speed=5")
inline unsigned char makePinMask(unsigned short int pin)