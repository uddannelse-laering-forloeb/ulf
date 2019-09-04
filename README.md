The full readme file for the project is located in the [ulf_profile folder](https://github.com/uddannelse-laering-forloeb/ulf/blob/master/profiles/ulf/README.md).


```sh
cat > sites/default/settings.php <<'EOF'
<?php

$databases['default']['default'] = [
  'database' => 'db',
  'username' => 'db',
  'password' => 'db',
  'host' => 'mariadb',
  'port' => '',
  'driver' => 'mysql',
  'prefix' => '',
];
EOF

git clone --branch feature/pretix https://github.com/uddannelse-laering-forloeb/ulf_pretix sites/all/modules/ulf_pretix
```


```sh
docker-compose up --detach
docker-compose run --rm drush --root=/app --yes pm-download field_group secure_permissions-7.x-2.x-dev
docker-compose run --rm drush --root=/app --yes pm-enable ulf_pretix
docker-compose run --rm drush --root=/app --yes features-revert-all
docker-compose run --rm drush --root=/app --yes secure-permissions on
docker-compose run --rm drush --root=/app --yes secure-permissions-rebuild
```

```sh
docker-compose run --rm drush --root=/app --yes --uri=http://ulf.docker.localhost:8080/ user-login
```

## Initialize pretix

```sh
docker-compose exec pretix python /pretix/src/manage.py migrate
docker-compose exec pretix python /pretix/src/manage.py compress
docker-compose exec pretix python /pretix/src/manage.py collectstatic --no-input
```

## Start pretix

If pretix does not run smoothly, you can try starting the development server in stead:

```sh
docker-compose exec -u 0 pretix bash -c "supervisorctl stop nginx";
docker-compose exec -u 0 pretix bash -c "python /pretix/src/manage.py runserver 0.0.0.0:80";
```

## Access pretix api

```sh
curl --header 'authorization: Token cqcchnjf3yv53ogoailu1a0tdzpwy6xcg7w2i40bofevzs856vorwbt6b38hvvao' \
  http://pretix.docker.localhost:8081/api/v1/organizers/
```



```sh
sudo bash -c 'echo 0.0.0.0 ulf.docker.localhost pretix.docker.localhost >> /etc/hosts'
```

Drupal: http://ulf.docker.localhost:8080/
pretix: http://pretix.docker.localhost:8081/


```sh
docker-compose exec pretix python /pretix/src/manage.py compress
```


## Log to `syslog`

```sh
docker-compose run --rm drush --root=/app --yes pm-disable dblog
docker-compose run --rm drush --root=/app --yes pm-enable syslog
```
