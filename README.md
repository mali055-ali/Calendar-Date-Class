# Date Class (C++)

A C++ class that models a calendar date, with built-in validation and
automatic correction of invalid input, plus two different display formats.

## Project Description

This project implements a `Date` class that can be constructed either from a
numeric month, a month name, or with no arguments at all (defaulting to
January 1, 2000). Rather than rejecting invalid dates outright, the class
corrects them to the closest valid date and reports the correction to the
console — so a date like month 15, day 32 is automatically resolved to a
sensible value instead of crashing or silently misbehaving.

## Features

- **Multiple constructors**
  - Default constructor → January 1, 2000
  - `Date(month, day, year)` — numeric month (e.g. `Date(3, 1, 2010)` → March 1, 2010)
  - `Date(monthName, day, year)` — string month name, case-insensitive (e.g. `Date("december", 15, 2012)`)
- **Automatic input correction** — out-of-range months are clamped to
  1–12, and out-of-range days are clamped to the nearest valid day for that
  month/year, with a descriptive console message on every correction
- **Leap year awareness** — February's valid day range correctly accounts
  for leap years using the standard leap year rule
- **Invalid month name handling** — an unrecognized month name resets the
  date to January 1, 2000 with a console warning, rather than throwing or
  crashing
- **Two output formats**
  - `printNumeric()` → `3/15/2012`
  - `printAlpha()` → `March 15, 2012`
- **Interactive test harness** — `main()` lets the user pick which
  constructor to exercise and enter the date interactively

## Technologies Used

- **Language:** C++
- **Libraries:** C++ Standard Library (`<iostream>`, `<string>`, `<cctype>`)

## Files

| File | Description |
|------|-------------|
| `main.cpp` | `Date` class implementation plus an interactive test harness |

## How It Works

1. `getDate()` prompts the user to choose a constructor (numeric month,
   month name, or default) and collects the relevant input.
2. The chosen `Date` constructor validates the month and day:
   - Months outside 1–12 are clamped to the nearest bound.
   - Days are checked against `daysPerMonth()` (which itself checks
     `isLeap()` for February) and clamped if out of range.
   - Any correction prints a message in the form
     `Invalid date values: Date corrected to M/D/Y.`
3. `main()` prints the resulting date in both numeric (`printNumeric`) and
   alphabetic (`printAlpha`) formats.

## Build & Run

```bash
g++ -o date_demo main.cpp
./date_demo
```

Example session:

```
Which Date constructor? (Enter 1, 2, or 3)
1 - Month Number
2 - Month Name
3 - default
1

month number? 15

day? 32

year? 2010

Invalid date values: Date corrected to 12/31/2010.

Numeric: 12/31/2010
Alpha:   December 31, 2010
```
