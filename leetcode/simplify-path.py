class Solution:
    def simplifyPath(self, path: str) -> str:
        path_stack = []
        for folder in path.split("/"):
            if folder == "" or folder == ".":
                continue
            elif folder == "..":
                if len(path_stack) > 0:
                    path_stack.pop(-1)
            else:
                path_stack.append(folder)
        return "/" + "/".join(path_stack)