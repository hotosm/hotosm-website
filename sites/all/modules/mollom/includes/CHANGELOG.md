# API changes

This library aims to provide a stable and reliable class for integration into other applications, avoiding backwards-incompatible changes, but that cannot always be guaranteed.

This file lists all major changes and additions to the PHP API for convenience.  "API" means the PHP class only; i.e., not the Mollom [REST API](http://mollom.com/api).

## Changes

2013-04-23: Visibility of `Mollom::query()` changed from `protected` to `public`.

* Only affects classes that are overriding the `Mollom::query()` method (rare).
* Simply change your overridden method accordingly.
* Cause: Custom and new/experimental Mollom API calls should not require dedicated class methods to work.

2012-12-14: `400 Bad (Client) Request` error handling.

* `Mollom::handleRequest()` throws a new `MollomBadRequestException` in case the local system time diverges too much from UTC.
* `Mollom::query()` returns a new possible `Mollom::REQUEST_ERROR` code (400) in case the local system time diverges too much from UTC.
* Cause: Too many support requests from users reporting authentication failures, which are caused by a local server time that is not synchronized with UTC.  The maximum allowed time offset is `Mollom::TIME_OFFSET_MAX`.
* All client implementations should check for this new error code (in the same places where authentication errors are handled already) and conditionally log and output a corresponding error message to site administrators along the lines of:

  > The server time of this site is incorrect. The time of the operating system is not synchronized with the Coordinated Universal Time (UTC), which prevents a successful authentication with Mollom. The maximum allowed offset is @minutes minutes. Please consult your hosting provider or server operator to correct the server time.


## Additions


