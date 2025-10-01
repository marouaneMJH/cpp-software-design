#!/bin/bash

# Vérifie si un programme a été fourni
if [ $# -lt 1 ]; then
    echo "Usage: $0 chemin_programme [args...]"
    exit 1
fi

PROGRAM="$1"
shift # supprime le premier argument pour garder les arguments restants

# Mesurer le temps d'exécution
echo "Exécution de $PROGRAM avec les arguments: $@"
time "$PROGRAM" "$@"
rime 