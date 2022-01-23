'''
A tool for generating engine's header file.
'''
import os
import sys

# Declaring this in the global scope so that we can reuse this script for another project.
ENGINE_HEADER_FILENAME = "engine.h"
ENGINE_INCLUDE_GUARD = "#pragma once"
IGNORE_LIST = {
    "external",
    ENGINE_HEADER_FILENAME
}

def isHeader(file):
    '''Checking whether the specified file is a header file.'''
    headerExts = {
        ".h", ".hpp"
    }
    return len(list(filter(lambda ext, _file = file: ext in _file, headerExts))) > 0

def main():
    scriptRoot, _ = os.path.split(os.path.abspath(sys.argv[0]))
    engineRoot = os.path.abspath(os.path.join(scriptRoot, ".."))
    projectRoot = os.path.abspath(os.path.join(engineRoot, ".."))
    headerList = set()

    for root, _, files in os.walk(engineRoot):
        for file in files:
            filepath = os.path.join(root, file)
            ignored = list(
                filter(lambda path, ignoredPath=filepath: path in ignoredPath, IGNORE_LIST)
            )
            if ignored:
                continue
            if isHeader(file):
                headerList.add(os.path.join(root, file))

    fileContent = "/** This file is auto generated and MUST NOT be manually modified **/\n"
    fileContent += f"{ENGINE_INCLUDE_GUARD}\n\n"
    sortedHeaders = list(headerList)
    sortedHeaders.sort()

    projectRootPathLen = len(projectRoot) + 1
    for headerFullPath in sortedHeaders:
        if projectRootPathLen >= len(headerFullPath):
            continue

        header = headerFullPath[projectRootPathLen:]
        fileContent += f"#include \"{header}\"\n"

    engineHeaderPath = os.path.join(engineRoot, ENGINE_HEADER_FILENAME)
    with open(engineHeaderPath, "w") as outFile:
        outFile.write(fileContent)

if __name__ == '__main__':
    main()
