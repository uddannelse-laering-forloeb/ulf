# ULF pretix

## Installation instructions

After enabling the module, it is possible to enable pretix for a user and define
pretix API connection settings on the user.

Go to `/admin/config/services/pretix` to set the url to the ULF/pretix manual to
help user administrators set up a user's pretix connection. The url to the
current manual is [http://korturl.dk/ailx](http://korturl.dk/ailx).

## ULF project relation

- Optional module

## Description

- Adds fields to user profiles and course for connecting to pretix through API
- Adds new field collection for mapping an event in pretix
- Holds code for connecting to pretix through pretix API

The module will add a 'pretix' section on all courses.

## Coding standards

```sh
composer install
composer check-coding-standards
```
